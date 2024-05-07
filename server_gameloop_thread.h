
#ifndef THREADS_2024C1_VICKYA5_SERVER_GAMELOOP_H
#define THREADS_2024C1_VICKYA5_SERVER_GAMELOOP_H

#include "server_game.h"
#include "server_thread.h"

class Gameloop: public Thread {
private:
    Game game;
    std::atomic<bool> continue_loop{true};

public:
    /*
     * Executes a loop that simulates an entire iteration for the gameloop. It calls a game
     * iteration, and sleeps 200 milliseconds in order to simulate 5 iterations per second.
     * */
    void run() override;


    /*
     * Sets continue_loop to false to tell the run() method to stop iterating.
     * */
    void stop() override;


    /*
     * Returns a reference to the clients commands queue.
     * */
    Queue<uint8_t>& get_clients_commands();

    /*
     * Returns a reference to the only instance of MapQueues.
     * */
    MapQueues& get_map_queues();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_GAMELOOP_H
