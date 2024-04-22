
#ifndef THREADS_2024C1_VICKYA5_SERVER_ACCEPTOR_H
#define THREADS_2024C1_VICKYA5_SERVER_ACCEPTOR_H

#include "common_socket.h"
#include <iostream>
#include "server_monitor_game.h"
#include "server_thread.h"

class AcceptorThread : public Thread {
private:
    Socket listener_skt;

public:
    explicit AcceptorThread(std::string& service_name);

    /*
     *
     * */
    void run();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_ACCEPTOR_H
