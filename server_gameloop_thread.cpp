
#include "server_gameloop_thread.h"

Gameloop::Gameloop(GameMonitor& the_game) : game(the_game){}

void Gameloop::run() {

    while (continue_loop) {
        // Debería proteger también acá?
        game.iteration();
        game.broadcast();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void Gameloop::stop_loop() {
    this->continue_loop = false;
}
