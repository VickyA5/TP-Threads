
#ifndef THREADS_2024C1_VICKYA5_MAPQUEUES_H
#define THREADS_2024C1_VICKYA5_MAPQUEUES_H

#include <iostream>
#include <map>
#include <mutex>
#include "server_queue.h"
#include "server_monitor_game.h"

class MapQueues {
private:
    std::map<size_t, Queue<GameMonitor>*> map_queues;
    std::mutex mtx;

public:

    /*
     *
     * */
    void addNewQueue(const size_t& idThrClient, Queue<GameMonitor>* aQueue);

};


#endif  // THREADS_2024C1_VICKYA5_MAPQUEUES_H
