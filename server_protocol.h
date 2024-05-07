
#ifndef THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H
#define THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H

#include <iostream>

#include "common_socket.h"
#include "server_message.h"

#define HEADER_SERVER 0x06
#define TOTAL_ENEMIES 5

class ServerProtocol {

private:
    Socket& skt;
    bool was_closed;

public:
    explicit ServerProtocol(Socket& a_skt);

    /*
     * Receives the message from the client and returns it.
     * */
    uint8_t receive_msg();

    /*
     * Sends the status of the game to the client with the given protocol.
     * */
    void send_status(ServerMessage message);

    /*
     * Returns true if the socket was closed.
     * */
    bool get_was_closed();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_PROTOCOL_H
