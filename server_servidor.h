
#ifndef THREADS_2024C1_VICKYA5_SERVER_SERVIDOR_H
#define THREADS_2024C1_VICKYA5_SERVER_SERVIDOR_H

#include <string>

#include "common_socket.h"
#include "server_acceptor_thread.h"
#include "server_game.h"
#include "server_gameloop_thread.h"

#define EXIT 'q'

class Server {
private:
    Socket acceptor_skt;

public:
    explicit Server(const char* service_name);
    int run();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_SERVIDOR_H
