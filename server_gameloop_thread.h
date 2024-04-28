
#ifndef THREADS_2024C1_VICKYA5_SERVER_GAMELOOP_H
#define THREADS_2024C1_VICKYA5_SERVER_GAMELOOP_H

#include "server_monitor_game.h"
#include "server_thread.h"
#include "server_protocol.h"

class Gameloop : public Thread {
private:
    GameMonitor& game;
    std::atomic<bool> continue_loop{true};

public:

    explicit Gameloop(GameMonitor& the_game);

    /*
     *
     * */
    void run() override;


    /*
     *
     * */
    void stop_loop();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_GAMELOOP_H
