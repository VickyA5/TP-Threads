
#include "common_status_printer.h"
#include "server_acceptor_thread.h"

AcceptorThread::AcceptorThread(Socket& skt,
                               Queue<uint8_t>& clients_commands_queue,
                               MapQueues& map_queues) :
        listener_skt(skt),
        clients_commands_queue(clients_commands_queue),
        map_queues(map_queues) {}

void AcceptorThread::run() {
    try {
        size_t id_client = 0;
        while (still_alive) {
            Socket new_client = listener_skt.accept();
            ReceiverThread* new_thread = new ReceiverThread(std::move(new_client),
                                                            clients_commands_queue,
                                                            map_queues,
                                                            id_client);
            clients.push_back(new_thread);
            Queue<ServerMessage>& server_msgs_queue = new_thread->get_server_msgs_queue();
            map_queues.add_new_queue(id_client, &server_msgs_queue);
            new_thread->start();
            clean_clients();
            id_client++;
        }
        //kill_all_clients();
    } catch (const std::exception& err) {
        // Se llega acá con el close del socket aceptador desde fuera
        if (still_alive) {
            std::cerr << "Unexpected exception at acceptor: " << err.what() << "\n";
        }
        //Llega acá, después se detiene en el join del acceptor
        kill_all_clients();
        still_alive = false;
    }
}

void AcceptorThread::clean_clients() {

    clients.remove_if([this](ReceiverThread* client) {
        if (!client->is_still_alive()) {
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
    still_alive = false;
    listener_skt.shutdown(2); //Unexpected exception: The queue is closed
    listener_skt.close();
}
