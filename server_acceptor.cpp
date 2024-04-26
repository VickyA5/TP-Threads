
#include "server_acceptor.h"
#include "common_status_printer.h"
#include "server_queue.h"
#include "common_map_queues.h"

AcceptorThread::AcceptorThread(Socket& skt) :
        listener_skt(skt) {}

void AcceptorThread::run() {
    try {
        while (still_alive) {

            Socket new_client = listener_skt.accept();
            // Me falta que cada playerThread, y luego cada receiver y sender conozcan al game
            // pero no sé cómo pasarlo
            PlayerThread* new_thread = new PlayerThread(std::move(new_client));
            clients.push_back(new_thread);
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

    clients.remove_if([this](PlayerThread* client) {
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
