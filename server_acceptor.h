
#ifndef THREADS_2024C1_VICKYA5_SERVER_ACCEPTOR_H
#define THREADS_2024C1_VICKYA5_SERVER_ACCEPTOR_H

#include "common_socket.h"
#include <iostream>
#include "server_monitor_game.h"
#include "server_thread.h"
#include <algorithm>
#include <list>
#include "server_player_thread.h"
#include "server_player_thread.h"

class AcceptorThread : public Thread {
private:
    Socket& listener_skt;
    std::list<PlayerThread*> clients;
    std::atomic<bool> still_alive{true};

public:
    explicit AcceptorThread(Socket& skt);

    /*
     *
     * */
    void run() override;

    /*
     *
     * */
    void clean_clients();

    /*
     *
     * */
    void kill_all_clients();

    /*
     *
     * */
    //bool get_still_alive() override;
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_ACCEPTOR_H
