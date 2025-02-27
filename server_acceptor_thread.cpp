
#include "server_acceptor_thread.h"

AcceptorThread::AcceptorThread(Socket& skt, Queue<uint8_t>& clients_commands_queue,
                               MapQueues& map_queues):
        listener_skt(skt), clients_commands_queue(clients_commands_queue), map_queues(map_queues) {}

void AcceptorThread::run() {
    try {
        size_t id_client = 0;
        while (still_alive) {
            Socket new_client = listener_skt.accept();
            ReceiverThread* new_thread = new ReceiverThread(
                    std::move(new_client), clients_commands_queue, map_queues, id_client);
            new_thread->start();
            reap_dead();
            Queue<ServerMessage>& server_msgs_queue = new_thread->get_server_msgs_queue();
            map_queues.add_new_queue(id_client, &server_msgs_queue);
            clients.push_back(new_thread);
            id_client++;
        }
        kill_all_clients();
    } catch (const std::exception& err) {
        kill_all_clients();
        still_alive = false;
    }
}

void AcceptorThread::reap_dead() {
    clients.remove_if([this](ReceiverThread* client) {
        if (client->is_dead()) {
            client->join();
            delete client;
            return true;
        }
        return false;
    });
}

void AcceptorThread::kill_all_clients() {
    for (auto& client: clients) {
        client->kill();
        client->join();
        delete client;
    }
    clients.clear();
}

void AcceptorThread::kill() {
    try {
        still_alive = false;
        listener_skt.shutdown(SHUTDOWN);
        listener_skt.close();
    } catch (const std::exception& err) {
        // Violent but granted way.
    }
}
