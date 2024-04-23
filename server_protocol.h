
#ifndef THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H
#define THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H

#include <iostream>

#include "common_socket.h"
#include "server_monitor_game.h"

#define HEADER_SERVER 0x06

class ServerProtocol {

private:
    Socket& skt;

public:
    explicit ServerProtocol(Socket& a_skt);

    /*
     *
     * */
    uint8_t receive_msg(GameMonitor & game);

    /*
     *
     * */
    void send_status(GameMonitor & game);
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H
