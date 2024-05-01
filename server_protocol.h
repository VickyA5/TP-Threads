
#ifndef THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H
#define THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H

#include <iostream>

#include "common_socket.h"
#include "server_game.h"

#define HEADER_SERVER 0x06

class ServerProtocol {

private:
    Socket& skt;

public:
    explicit ServerProtocol(Socket& a_skt);

    /*
     *
     * */
    uint8_t receive_msg();

    /*
     *
     * */
    void send_status(uint16_t alive_cnt, uint8_t last_type_event);
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H
