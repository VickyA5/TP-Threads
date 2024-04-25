
#ifndef THREADS_2024C1_VICKYA5_MAPQUEUES_H
#define THREADS_2024C1_VICKYA5_MAPQUEUES_H

#include <iostream>
#include <map>
#include <mutex>
#include <array>
#include "server_queue.h"
#include "server_monitor_game.h"

class MapQueues {
private:
    // Por ahora haré que los mensajes del server se encolen así, luego haré un tipo de dato para
    // encapsularlo.
    std::map<size_t, Queue<std::array<uint16_t, 4>>*> server_messages;
    Queue<uint8_t> clients_commands;
    std::mutex mtx;

public:
    MapQueues();

    /*
     *
     * */
    void add_new_queue(const size_t& idThrClient, Queue<std::array<uint16_t, 4>>* a_queue);

    /*
     *
     * */
    void push_attack_to_clients_queue();

    uint8_t pop_clients_commands();

};


#endif  // THREADS_2024C1_VICKYA5_MAPQUEUES_H
