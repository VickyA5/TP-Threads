
#include "common_map_queues.h"

MapQueues::MapQueues() {}

void MapQueues::push_attack_to_clients_queue() {
    std::lock_guard<std::mutex> lck(mtx);
    // o quizas try_push
    clients_commands.push(ATTACK);
}

uint8_t MapQueues::pop_clients_commands() {
    std::lock_guard<std::mutex> lck(mtx);
    // o quizas try_pop
    return clients_commands.pop();
}
