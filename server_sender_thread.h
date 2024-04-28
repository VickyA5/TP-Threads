
#ifndef THREADS_2024C1_VICKYA5_SERVER_SENDER_THREAD_H
#define THREADS_2024C1_VICKYA5_SERVER_SENDER_THREAD_H

#include "server_thread.h"
#include "common_socket.h"

class SenderThread : public Thread {
private:
    Socket& client_skt;
    GameMonitor& game;

public:
    SenderThread(Socket& skt, GameMonitor& the_game);

    /*
     *
     * */
    void run() override;
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_SENDER_THREAD_H
