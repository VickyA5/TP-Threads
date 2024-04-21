
#include "common_game.h"

Game::Game() : enemies({true, true, true, true, true}) {
    this->last_type_event = -1;
}

// Mas adelante tener cuidado con proteger estos recursos, y fijarme si no hay problema
// con tener problema con la posicion de memoria si se me mueve.
void Game::kill_enemy() {
    this->last_type_event = KILLED;
    for (bool& enemy : enemies) {
        if (enemy) {
            enemy = false;
            return;
        }
    }
}

void Game::revive_enemy() {
    this->last_type_event = REVIVED;
    for (bool& enemy : enemies) {
        if (!enemy) {
            enemy = true;
            return;
        }
    }
}

int Game::get_alive_cnt() const {
    int alive = 0;
    for (bool enemy : enemies) {
        if (enemy)
            alive++;
    }
    return alive;
}

uint8_t  Game::get_last_type_event() {
    return last_type_event;
}
