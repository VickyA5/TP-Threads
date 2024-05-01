
#include "server_game.h"

Game::Game() {
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

void Game::revive_enemy() {
    this->last_type_event = REVIVED;
    for (Enemy& enemy : enemies) {
        // Todos los enemigos deben enterarse que sucedió una iteración, y si corresponde reviven.
        enemy.try_revive();
    }
}

int Game::get_alive_cnt()  {
    int alive = 0;
    for (Enemy& enemy : enemies) {
        if (enemy.is_alive())
            alive++;
    }
    return alive;
}

void Game::iteration() {
    uint8_t last_command = map_queues.pop_clients_commands();
    if (last_command == ATTACK)
        kill_enemy();
    revive_enemy();
}

void Game::broadcast() {
    int alive_cnt = get_alive_cnt();
    map_queues.broadcast(alive_cnt, last_type_event);
}

void Game::push_attack_to_queue() {
    map_queues.push_attack_to_clients_queue();
}

Queue<uint8_t>& Game::get_clients_commands() {
    return clients_commands;
}
