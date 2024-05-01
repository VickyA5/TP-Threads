
#ifndef THREADS_2024C1_VICKYA5_MAPQUEUES_H
#define THREADS_2024C1_VICKYA5_MAPQUEUES_H

#include <array>
#include <map>
#include <mutex>
#include "server_queue.h"
#include "server_message.h"

class MapQueues {
private:
    std::map<size_t, Queue<ServerMessage>*> server_messages;
    std::mutex mtx;

public:
    MapQueues();

    /*
     *
     * void add_new_queue(const size_t& idThrClient, Queue<std::array<uint16_t, 4>>* a_queue);
     * */
    void add_new_queue(Queue<ServerMessage>* a_queue);

    /*
     *
     * */
    void push_server_message();

    /*
     *
     * */
    void broadcast(int alive_cnt, uint8_t last_type_event);
};


#endif  // THREADS_2024C1_VICKYA5_MAPQUEUES_H
