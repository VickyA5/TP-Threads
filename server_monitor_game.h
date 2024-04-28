
#ifndef THREADS_2024C1_VICKYA5_SERVER_MONITOR_GAME_H
#define THREADS_2024C1_VICKYA5_SERVER_MONITOR_GAME_H

#include <array>
#include <iostream>
#include "server_enemy.h"
#include "server_map_queues.h"
#include "server_queue.h"

#define ATTACK 0x03
#define KILLED 0x04
#define REVIVED 0x05

class GameMonitor {
private:
    std::array<Enemy, 5> enemies;
    uint8_t last_type_event;
    std::mutex game_mutex;
    MapQueues map_queues;

    /*
     * Kills an enemy. If all of them were already dead, nothing happens.
     * */
    void kill_enemy();

    /*
     * Revives an enemy. If all of them were already alive, nothing happens.
     * */
    void revive_enemy();

    /*
     *
     * */
    int get_alive_cnt();

public:
    GameMonitor();

    /*
     *
     * */
    void iteration();

    /*
     *
     * */
    void broadcast();

    /*
     *
     * */
    void push_attack_to_queue();

    /*
     *
     * */
    void push_server_msg();

};


#endif  // THREADS_2024C1_VICKYA5_SERVER_MONITOR_GAME_H
