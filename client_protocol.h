
#ifndef THREADS_2024C1_VICKYA5_CLIENT_PROTOCOL_H
#define THREADS_2024C1_VICKYA5_CLIENT_PROTOCOL_H

#include <array>
#include <iostream>

#include <netinet/in.h>

#include "common_socket.h"

#define ATTACK 0x03
#define SHUTDOWN 2

class ClientProtocol {

private:
    Socket socket;
    bool was_closed;

public:
    ClientProtocol(const char* host_name, const char* service_name);

    /*
     * Sends the literal number '0x03' to the server, which means "attack".
     * */
    void send_msg_attack();

    /*
     * Receives the server's msg according to the protocol:
     * 0x06 <enemies alive cnt> <enemies dead cnt> <type event>
     * Returns the number of enemies alive.
     * */
    uint16_t receive_msg(uint8_t& type_event);

    /*
     * Closes the connection with the client's socket.
     * */
    void close_connection();
};


#endif  // THREADS_2024C1_VICKYA5_CLIENT_PROTOCOL_H
