
#include "server_servidor.h"

#include "server_map_queues_monitor.h"

Server::Server(const char* service_name): acceptor_skt(service_name) {}

int Server::run() {

    MapQueues map_queues;
    Gameloop gameloop(map_queues);
    Queue<uint8_t>& clients_commands_queue = gameloop.get_clients_commands();
    AcceptorThread acceptor(acceptor_skt, clients_commands_queue, map_queues);
    acceptor.start();
    gameloop.start();
    while (std::cin.get() != EXIT) {}
    clients_commands_queue.close();
    gameloop.stop();
    acceptor.kill();
    acceptor.join();
    gameloop.join();

    return 0;
}
