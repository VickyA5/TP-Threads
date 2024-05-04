
#include "server_gameloop_thread.h"

Gameloop::Gameloop(MapQueues& map_queues) : map_queues(map_queues){}

void Gameloop::run() {

    while (continue_loop) {
        game.iteration();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    game.stop_game();
    std::cout << "Se cierra el juego" << std::endl;
}

void Gameloop::stop() {
    this->continue_loop = false;
}

Queue<uint8_t>& Gameloop::get_clients_commands() {
    return game.get_clients_commands();
}
