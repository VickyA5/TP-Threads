
#include "server_map_queues_monitor.h"

MapQueues::MapQueues() {}

// o try_push ?
void MapQueues::broadcast(int alive_cnt, uint8_t last_type_event) {
    std::unique_lock<std::mutex> lck(mtx);
    for (auto& pair : server_messages) {
        auto& queue_ptr = pair.second;
        if (queue_ptr) {
            ServerMessage new_message(alive_cnt, last_type_event);
            queue_ptr->push(new_message);
        }
    }
}

void MapQueues::add_new_queue(Queue<ServerMessage>* a_queue) {
    //server_messages.insert();
}
