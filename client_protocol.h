
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
     * Sends the literal number 0x03 to the server, wich means "attack".
     * */
    void send_msg_attack();

    /*
     * Receives the server's msg according to the protocol:
     * 0x06 <enemies alive cnt> <enemies dead cnt> <type event> donde 0x06 es un byte con el
     * número literal 0x06, <enemies alive cnt> son 2 bytes sin signo en big endian con la cantidad
     * de enemigos vivos, <enemies dead cnt> son 2 bytes sin signo en big endian con la cantidad de
     * enemigos muertos y <type event> es un campo de un byte indicando el evento sucedido.
     *
     * Returns the number of alive enemies.
     * */
    int receive_msg(uint8_t& type_event);

    /*
     *
     * */
    void close_connection();
};


#endif  // THREADS_2024C1_VICKYA5_CLIENT_PROTOCOL_H
