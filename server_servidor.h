
#ifndef THREADS_2024C1_VICKYA5_SERVER_SERVIDOR_H
#define THREADS_2024C1_VICKYA5_SERVER_SERVIDOR_H

#include <string>

#include "common_socket.h"
#include "server_acceptor_thread.h"
#include "server_gameloop_thread.h"

#define EXIT 'q'

class Server {
private:
    Socket acceptor_skt;

public:
    explicit Server(const char* service_name);

    /*
     * Initializes the acceptor thread and the gameloop thread. When the user enters a 'q', it
     * closes the commands queue, and stops and join the threads.
     * */
    int run();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_SERVIDOR_H
