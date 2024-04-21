
#include "client_protocol.h"

ClientProtocol::ClientProtocol(const char* host_name, const char* service_name) :
        socket(host_name, service_name) {}

void ClientProtocol::send_msg_attack() {
    bool was_closed = false;
    uint8_t msg = ATTACK;
    socket.sendall(&msg, sizeof(uint8_t), &was_closed);
    if (was_closed) {
        throw std::runtime_error("Client message couldn't be sent. Server's socket "
                                 "was closed.");
    }
}

int ClientProtocol::receive_msg(uint8_t & type_event) {
    bool was_closed = false;
    uint8_t header = 0;
    uint16_t enemies_alive = 0;
    uint16_t enemies_dead = 0;
    uint8_t type_event_r = 0;

    socket.recvall(&header, sizeof(uint8_t), &was_closed);

    socket.recvall(&enemies_alive, sizeof(uint16_t), &was_closed);
    enemies_alive = htons(enemies_alive);

    socket.recvall(&enemies_dead, sizeof(uint16_t), &was_closed);
    enemies_dead = htons(enemies_dead);

    socket.recvall(&type_event_r, sizeof(uint8_t), &was_closed);
    type_event = type_event_r;
    if (was_closed) {
        throw std::runtime_error("Server message couldn't be received.");
    }
    return (int) enemies_alive;
}

