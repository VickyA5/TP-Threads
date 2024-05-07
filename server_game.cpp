
#include "server_game.h"

Game::Game() { this->last_type_event = 0; }

void Game::kill_enemy() {
    this->last_type_event = KILLED;
    for (Enemy& enemy: enemies) {
        bool was_killed = enemy.kill();
        if (was_killed) {
            return;
        }
    }
}

bool Game::revive_enemy() {
    this->last_type_event = REVIVED;
    int revived_enemies = 0;
    for (Enemy& enemy: enemies) {
        if (enemy.try_revive())
            revived_enemies++;
    }
    return (revived_enemies > 0);
}

uint16_t Game::get_alive_cnt() {
    uint16_t alive = 0;
    for (Enemy& enemy: enemies) {
        if (enemy.is_alive())
            alive++;
    }
    return alive;
}

void Game::iteration() {
    try {
        uint8_t last_command = 0;
        clients_commands.try_pop(last_command);
        if (last_command == ATTACK && (get_alive_cnt() > 0)) {
            kill_enemy();
            print_and_broadcast();
        }
        bool an_enemy_was_revived = revive_enemy();
        if (an_enemy_was_revived) {
            print_and_broadcast();
        }
    } catch (const std::exception& err) {
        // In case the queue is closed.
    }
}

void Game::broadcast() {
    uint16_t alive_cnt = get_alive_cnt();
    map_queues.broadcast(alive_cnt, last_type_event);
}

void Game::print_and_broadcast() {
    printer.print_status(last_type_event, get_alive_cnt());
    broadcast();
}

Queue<uint8_t>& Game::get_clients_commands() { return clients_commands; }

MapQueues& Game::get_map_queues() { return map_queues; }
