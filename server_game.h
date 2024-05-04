
#ifndef THREADS_2024C1_VICKYA5_SERVER_GAME_H
#define THREADS_2024C1_VICKYA5_SERVER_GAME_H

#include <array>
#include <iostream>
#include "server_enemy.h"
#include "server_map_queues_monitor.h"
#include "server_queue.h"
#include "common_status_printer.h"

#define ATTACK 0x03
#define KILLED 0x04
#define REVIVED 0x05

class Game {
private:
    std::array<Enemy, 5> enemies;
    uint8_t last_type_event;
    MapQueues map_queues;
    Queue<uint8_t> clients_commands;

    /*
     * Kills an enemy. If all of them were already dead, nothing happens.
     * */
    void kill_enemy();

    /*
     * Revives an enemy. If all of them were already alive, nothing happens.
     * */
    bool revive_enemy();

    /*
     *
     * */
    uint16_t get_alive_cnt();

    /*
     *
     * */
    void broadcast();

public:
    Game();

    /*
     *
     * */
    void iteration();

    /*
     *
     * */
    Queue<uint8_t>& get_clients_commands();

    void stop_game();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_GAME_H
