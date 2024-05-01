
#include "common_status_printer.h"
#include "server_acceptor_thread.h"

AcceptorThread::AcceptorThread(Socket& skt, Queue<uint8_t>& clients_commands_queue,
                               MapQueues& map_queues) :
        listener_skt(skt), clients_commands_queue(clients_commands_queue),
        map_queues(map_queues) {}

void AcceptorThread::run() {
    try {
        while (still_alive) {
            Socket new_client = listener_skt.accept();
            ReceiverThread* new_thread = new ReceiverThread(std::move(new_client),
                                                            clients_commands_queue);
            clients.push_back(new_thread);
            Queue<ServerMessage>& server_msgs_queue = new_thread->get_server_msgs_queue();
            //revisar temas punteros
            map_queues.add_new_queue(&server_msgs_queue);
            new_thread->start();
            clean_clients();
        }
    } catch (const std::exception& err) {
        if (still_alive) {
            std::cerr << "Unexpected exception: " << err.what() << "\n";
        }
        kill_all_clients();
        still_alive = false;
    }
}

void AcceptorThread::clean_clients() {

    clients.remove_if([this](ReceiverThread* client) {
        //REVISAR lo de is_still_alive
        if (!client->is_still_alive()) {
            client->join();
            delete client;
            return true;
        }
        return false;
    });
}

//void AcceptorThread::kill()

void AcceptorThread::kill_all_clients() {
    for (auto& client: clients) {
        client->kill();
        client->join();
        delete client;
    }
    clients.clear();
}

void AcceptorThread::stop_acceptor() {
    this->still_alive = false;
}
