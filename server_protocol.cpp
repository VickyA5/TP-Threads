
#include "server_protocol.h"
#include <netinet/in.h>

ServerProtocol::ServerProtocol(const char* service_name) : skt(service_name) {
    Socket peer = skt.accept();
    skt = std::move(peer);
}

void ServerProtocol::receive_msg(Game & game, bool * connected) {
    bool was_closed = false;
    uint8_t msg = 0;
    skt.recvall(&msg, sizeof(uint8_t), &was_closed);
    if (msg == ATTACK) {
        game.kill_enemy();
        StatusPrinter printer;
        printer.printStatus(game.get_last_type_event(), game.get_alive_cnt());
    }

    if (was_closed) {
        *connected = false;
        return;
    }

}

void ServerProtocol::send_status(Game& game) {
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
