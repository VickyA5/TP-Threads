
#include "server_gameloop_thread.h"

void Gameloop::run() {

    while (continue_loop) {
        game.iteration();
        game.broadcast();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void Gameloop::stop_loop() {
    this->continue_loop = false;
}
