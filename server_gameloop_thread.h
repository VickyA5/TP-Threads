
#ifndef THREADS_2024C1_VICKYA5_SERVER_GAMELOOP_H
#define THREADS_2024C1_VICKYA5_SERVER_GAMELOOP_H

#include "server_game.h"
#include "server_thread.h"

class Gameloop : public Thread {
private:
    Game game;
    std::atomic<bool> continue_loop{true};

public:

    explicit Gameloop(MapQueues& map_queues);

    /*
     *
     * */
    void run() override;


    /*
     *
     * */
    void stop() override;


    /*
     *
     * */
    Queue<uint8_t>& get_clients_commands();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_GAMELOOP_H
