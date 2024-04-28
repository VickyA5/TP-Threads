
#include "server_map_queues.h"

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

void MapQueues::broadcast(int alive_cnt, uint8_t last_type_event) {
    //enviarle el mensaje a todos los clientes activos
}
