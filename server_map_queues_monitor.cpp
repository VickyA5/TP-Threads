
#include "server_map_queues_monitor.h"

MapQueues::MapQueues() {}

// o try_push ?
void MapQueues::broadcast(uint16_t alive_cnt, uint8_t last_type_event) {
    std::unique_lock<std::mutex> lck(mtx);
    // Estoy poniendo una copia del mismo mensaje en todas las queues, leaks?
    ServerMessage new_message(last_type_event, alive_cnt);
    for (auto& pair : server_messages) {
        auto& queue_ptr = pair.second;
        if (queue_ptr) {
            queue_ptr->push(new_message);
        }
    }
}

void MapQueues::add_new_queue(Queue<ServerMessage>& new_queue) {
    std::lock_guard<std::mutex> lock(mtx);
    size_t new_id = 1; // REFACTORIZAR SI ES QUE USO MAP
    server_messages[new_id] = &new_queue;
}
