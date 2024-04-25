
#include "server_monitor_game.h"


// fijarme si no hay problema con tener problema con la posición de memoria si se me mueve.
void GameMonitor::kill_enemy() {
    std::lock_guard<std::mutex> lck(game_mutex);
    this->last_type_event = KILLED;
    for (Enemy& enemy : enemies) {
        bool was_killed = enemy.kill();
        if (was_killed) {
            return;
        }
    }
}

void GameMonitor::revive_enemy() {
    std::lock_guard<std::mutex> lck(game_mutex);
    this->last_type_event = REVIVED;
    for (Enemy& enemy : enemies) {
        // Todos los enemigos deben enterarse que sucedió una iteración, y si corresponde reviven.
        enemy.try_revive();
    }
}

int GameMonitor::get_alive_cnt()  {
    //Realmente hace falta bloquear aca?
    std::lock_guard<std::mutex> lck(game_mutex);
    int alive = 0;
    for (Enemy& enemy : enemies) {
        if (enemy.is_alive())
            alive++;
    }
    return alive;
}

uint8_t GameMonitor::get_last_type_event() {
    return last_type_event;
}

void GameMonitor::iteration() {
    // por de la queue de los clients y si es attack llamar a kill. llamar siempre a revive
    uint8_t last_command = map_queues.pop_clients_commands();
    if (last_command == 0x03)
        kill_enemy();
    revive_enemy();
}
