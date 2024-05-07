
#ifndef THREADS_2024C1_VICKYA5_SERVER_GAME_H
#define THREADS_2024C1_VICKYA5_SERVER_GAME_H

#include <array>
#include <iostream>

#include "common_status_printer.h"
#include "server_enemy.h"
#include "server_map_queues_monitor.h"
#include "server_queue.h"

#define ATTACK 0x03
#define KILLED 0x04
#define REVIVED 0x05

class Game {
private:
    std::array<Enemy, 5> enemies;
    uint8_t last_type_event;
    MapQueues map_queues;
    Queue<uint8_t> clients_commands;
    StatusPrinter printer;

    /*
     * Kills 1 enemy. If all of them were already dead, nothing happens.
     * */
    void kill_enemy();

    /*
     * Calls the try_revive method of each enemy. If all of them were already alive,
     * nothing happens.
     * */
    bool revive_enemy();

    /*
     * Returns the amount of alive enemies.
     * */
    uint16_t get_alive_cnt();

    /*
     * Delegates the broadcast of the events to the only instance of MapQueues, which updates all
     * the existent client´s queues with the latest event and alive enemies amount.
     * */
    void broadcast();

    /*
     * Calls the printer´s method and broadcast method.
     * */
    void print_and_broadcast();

public:
    Game();

    /*
     * Simulates an iteration of the game. It reads a command sent by a client and executes it. If
     * the command is attack and and there is at least 1 enemy alive, it kills 1 enemy.
     * If an enemy reaches 15 iterations dead, it revives. If any of said actions is executed, the
     * game delegates the broadcast.
     * */
    void iteration();

    /*
     * Returns a reference to the queue that contais the clients commands. This queue is unique.
     * */
    Queue<uint8_t>& get_clients_commands();

    /*
     * Returns a reference to the class that contains the mapping of the client´s queue. There is a
     * queue for each client, and this class is used to broadcast the events.
     * */
    MapQueues& get_map_queues();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_GAME_H
