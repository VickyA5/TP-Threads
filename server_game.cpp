
#include "server_game.h"

Game::Game(MapQueues& map_queues) : map_queues(map_queues) {
    this->last_type_event = 0;
}

// fijarme si no hay problema con tener problema con la posición de memoria si se me mueve.
void Game::kill_enemy() {
    this->last_type_event = KILLED;
    for (Enemy& enemy : enemies) {
        bool was_killed = enemy.kill();
        if (was_killed) {
            return;
        }
    }
}

bool Game::revive_enemy() {
    this->last_type_event = REVIVED;
    bool an_enemy_was_revived = false;
    for (Enemy& enemy : enemies) {
        // Todos los enemigos deben enterarse que sucedió una iteración, y si corresponde reviven.
        an_enemy_was_revived = enemy.try_revive();
    }
    return an_enemy_was_revived;
}

uint16_t Game::get_alive_cnt()  {
    uint16_t alive = 0;
    for (Enemy& enemy : enemies) {
        if (enemy.is_alive())
            alive++;
    }
    return alive;
}

void Game::iteration() {
    //Primero elimino las colas cerradas?
    StatusPrinter printer;
    uint8_t last_command = clients_commands.pop();
    if (last_command == ATTACK) {
        kill_enemy();
        printer.print_status(last_type_event,get_alive_cnt());
        broadcast();
    }
    bool an_enemy_was_revived = revive_enemy();
    if (an_enemy_was_revived)
        broadcast();
}

void Game::broadcast() {
    uint16_t alive_cnt = get_alive_cnt();
    map_queues.broadcast(alive_cnt, last_type_event);
}

Queue<uint8_t>& Game::get_clients_commands() {
    return clients_commands;
}

void Game::stop_game() {
    clients_commands.close();
}
