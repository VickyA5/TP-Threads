
#ifndef THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H
#define THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H

#include <iostream>

#include "common_socket.h"
#include "common_status_printer.h"
#include "server_monitor_game.h"

#define HEADER_SERVER 0x06
#define ATTACK 0x03

class ServerProtocol {

private:
    Socket skt;

public:
    explicit ServerProtocol(const char* service_name);

    /*
     *
     * */
    void receive_msg(Game & game, bool * connected);

    /*
     *
     * */
    void send_status(Game & game);
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H
