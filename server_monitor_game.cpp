
#include "server_monitor_game.h"

GameMonitor::GameMonitor() : enemies({true, true, true, true, true}) {
    this->last_type_event = -1;
}

// fijarme si no hay problema con tener problema con la posicion de memoria si se me mueve.
void GameMonitor::kill_enemy() {
    std::lock_guard<std::mutex> lck(game_mutex);
    this->last_type_event = KILLED;
    for (bool& enemy : enemies) {
        if (enemy) {
            enemy = false;
            return;
        }
    }
}

void GameMonitor::revive_enemy() {
    std::lock_guard<std::mutex> lck(game_mutex);
    this->last_type_event = REVIVED;
    for (bool& enemy : enemies) {
        if (!enemy) {
            enemy = true;
            return;
        }
    }
}

int GameMonitor::get_alive_cnt()  {
    //Realmente hace falta bloquear aca?
    std::lock_guard<std::mutex> lck(game_mutex);
    int alive = 0;
    for (bool enemy : enemies) {
        if (enemy)
            alive++;
    }
    return alive;
}

uint8_t GameMonitor::get_last_type_event() {
    return last_type_event;
}
