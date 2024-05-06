
#ifndef THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H
#define THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H

#include <iostream>

#include "common_socket.h"
#include "server_message.h"

#define HEADER_SERVER 0x06

class ServerProtocol {

private:
    Socket& skt;
    bool was_closed;

public:
    explicit ServerProtocol(Socket& a_skt);

    /*
     *
     * */
    uint8_t receive_msg();

    /*
     *
     * */
    void send_status(ServerMessage message);

    /*
     *
     * */
    bool get_was_closed();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H
