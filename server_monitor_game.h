
#ifndef THREADS_2024C1_VICKYA5_SERVER_MONITOR_GAME_H
#define THREADS_2024C1_VICKYA5_SERVER_MONITOR_GAME_H

#include <array>
#include <iostream>
#include "server_queue.h"
#include "server_enemy.h"
#include "common_map_queues.h"

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
     * Asesina a un enemigo. Si todos se encontraban muertos, no pasa nada.
     * */
    void kill_enemy();

    /*
     * Revive a un enemigo. Si todos se encontraban vivos, no pasa nada.
     * */
    void revive_enemy();

    /*
     *
     * */
    int get_alive_cnt();

public:

    /*
     *
     * */
    void iteration();

    /*
     *
     * */
    void broadcast();

};


#endif  // THREADS_2024C1_VICKYA5_SERVER_MONITOR_GAME_H
