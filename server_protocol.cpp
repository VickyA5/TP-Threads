
#include "server_protocol.h"
#include <netinet/in.h>

ServerProtocol::ServerProtocol(Socket& a_skt) : skt(a_skt) {}

uint8_t ServerProtocol::receive_msg() {
    bool was_closed = false;
    uint8_t msg = 0;
    skt.recvall(&msg, sizeof(uint8_t), &was_closed);
    return msg;
}

//Deberia recibir como parametro al map de queues
void ServerProtocol::send_status(GameMonitor& game) {
    bool was_closed = false;
    uint8_t header_server = HEADER_SERVER;
    uint16_t enemies_alive_cnt = (uint16_t) game.get_alive_cnt();
    enemies_alive_cnt = ntohs(enemies_alive_cnt);
    uint16_t enemies_dead_cnt = 5 - enemies_alive_cnt;
    enemies_dead_cnt = ntohs(enemies_dead_cnt);
    uint8_t last_type_event = game.get_last_type_event();

    skt.sendall(&header_server, sizeof(uint8_t), &was_closed);
    skt.sendall(&enemies_alive_cnt, sizeof(uint16_t), &was_closed);
    skt.sendall(&enemies_dead_cnt, sizeof(uint16_t), &was_closed);
    skt.sendall(&last_type_event, sizeof(uint8_t), &was_closed);

    if (was_closed) {
        throw std::runtime_error("Server message couldn't be sent, the socket was closed.");
    }
}
