
#include "server_protocol.h"

#include <netinet/in.h>

ServerProtocol::ServerProtocol(Socket& a_skt): skt(a_skt), was_closed(false) {}

uint8_t ServerProtocol::receive_msg() {
    try {
        uint8_t msg = 0;
        skt.recvall(&msg, sizeof(uint8_t), &was_closed);
        return msg;
    } catch (const std::exception& err) {
        std::cerr << "Exception: " << err.what() << "\n";
        return -1;
    }
}

void ServerProtocol::send_status(ServerMessage message) {
    uint8_t header_server = HEADER_SERVER;
    uint8_t last_type_event = message.get_type_event();

    uint16_t enemies_alive_cnt = message.get_alive_cnt();
    uint16_t enemies_dead_cnt = TOTAL_ENEMIES - enemies_alive_cnt;

    enemies_alive_cnt = ntohs(enemies_alive_cnt);
    enemies_dead_cnt = ntohs(enemies_dead_cnt);

    skt.sendall(&header_server, sizeof(uint8_t), &was_closed);
    skt.sendall(&enemies_alive_cnt, sizeof(uint16_t), &was_closed);
    skt.sendall(&enemies_dead_cnt, sizeof(uint16_t), &was_closed);
    skt.sendall(&last_type_event, sizeof(uint8_t), &was_closed);
}

bool ServerProtocol::get_was_closed() { return was_closed; }
