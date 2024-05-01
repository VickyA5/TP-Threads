
#include "server_gameloop_thread.h"

Gameloop::Gameloop(MapQueues& map_queues) : map_queues(map_queues){}

void Gameloop::run() {

    while (continue_loop) {
        // Debería proteger también acá?
        game.iteration();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void Gameloop::stop_loop() {
    this->continue_loop = false;
}

Queue<uint8_t>& Gameloop::get_clients_commands() {
    return game.get_clients_commands();
}
