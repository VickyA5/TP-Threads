
#include "server_map_queues.h"

MapQueues::MapQueues() {}


// o try_push ?
void MapQueues::broadcast(int alive_cnt, uint8_t last_type_event) {
    for (auto& pair : server_messages) {
        auto& queue_ptr = pair.second;
        if (queue_ptr) {
            std::array<uint8_t, 2> message = {(uint8_t) alive_cnt, last_type_event};
            queue_ptr->push(message);
        }
    }
}
