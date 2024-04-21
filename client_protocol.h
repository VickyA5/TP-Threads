
#ifndef THREADS_2024C1_VICKYA5_CLIENT_PROTOCOL_H
#define THREADS_2024C1_VICKYA5_CLIENT_PROTOCOL_H

#include "common_socket.h"
#include <iostream>
#include <netinet/in.h>
#include <array>

#define ATTACK 0x03

class ClientProtocol {

private:
    Socket socket;
public:
    ClientProtocol(const char* host_name, const char* service_name);
    void send_msg_attack();
    int receive_msg(uint8_t & type_event);
};


#endif  // THREADS_2024C1_VICKYA5_CLIENT_PROTOCOL_H
