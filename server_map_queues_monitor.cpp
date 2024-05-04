
#include "server_map_queues_monitor.h"

MapQueues::MapQueues() {}

// o try_push ?
void MapQueues::broadcast(uint16_t alive_cnt, uint8_t last_type_event) {
    std::unique_lock<std::mutex> lck(mtx);
    // Estoy poniendo una copia del mismo mensaje en todas las queues, ta bien?
    ServerMessage new_message(last_type_event, alive_cnt);
    for (auto& element : server_messages) {
        auto& queue_ptr = element.second;
        if (queue_ptr) {
            queue_ptr->push(new_message);
        }
    }

}

void MapQueues::add_new_queue(const size_t id_client, Queue<ServerMessage>* new_queue) {
    std::lock_guard<std::mutex> lock(mtx);
    server_messages[id_client] = new_queue;
}

void MapQueues::delete_queue(size_t id_to_delete) {
    std::lock_guard<std::mutex> lock(mtx);
    server_messages[id_to_delete]->close();
    server_messages.erase(id_to_delete);
}
