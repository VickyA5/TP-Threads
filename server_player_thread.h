
#ifndef THREADS_2024C1_VICKYA5_SERVER_PLAYER_THREAD_H
#define THREADS_2024C1_VICKYA5_SERVER_PLAYER_THREAD_H

#include "server_sender_thread.h"
#include "server_receiver_thread.h"
#include "common_socket.h"
#include "server_monitor_game.h"
#include "server_queue.h"

class PlayerThread : public Thread {
private:
    Socket peer;
    std::atomic<bool> still_alive{true};

public:

    explicit PlayerThread(Socket skt_peer);

    /*
     *
     * */
    void run() override;

    /*
     *
     * */
    void kill();

    /*
     *
     * */
    bool is_still_alive();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_PLAYER_THREAD_H
