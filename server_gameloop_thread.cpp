
#include "server_gameloop_thread.h"

void Gameloop::run() {
    while (continue_loop) {
        game.iteration();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void Gameloop::stop() { this->continue_loop = false; }

Queue<uint8_t>& Gameloop::get_clients_commands() { return game.get_clients_commands(); }

MapQueues& Gameloop::get_map_queues() { return game.get_map_queues(); }
