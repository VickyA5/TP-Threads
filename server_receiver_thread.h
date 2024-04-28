
#ifndef THREADS_2024C1_VICKYA5_SERVER_RECEIVER_THREAD_H
#define THREADS_2024C1_VICKYA5_SERVER_RECEIVER_THREAD_H

#include "server_thread.h"
#include "common_socket.h"
#include "server_protocol.h"
#include "server_queue.h"

class ReceiverThread : public Thread {
private:
    Socket& client_skt;
    GameMonitor& game;


public:
    ReceiverThread(Socket& skt, GameMonitor& the_game);

    /*
     *
     * */
    void run() override;

};


#endif  // THREADS_2024C1_VICKYA5_SERVER_RECEIVER_THREAD_H
