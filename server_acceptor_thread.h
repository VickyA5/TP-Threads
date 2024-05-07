
#ifndef THREADS_2024C1_VICKYA5_SERVER_ACCEPTOR_THREAD_H
#define THREADS_2024C1_VICKYA5_SERVER_ACCEPTOR_THREAD_H

#include <algorithm>
#include <iostream>
#include <list>
#include <utility>

#include "common_socket.h"
#include "server_map_queues_monitor.h"
#include "server_receiver_thread.h"
#include "server_thread.h"

class AcceptorThread: public Thread {
private:
    Socket& listener_skt;
    std::list<ReceiverThread*> clients;
    std::atomic<bool> still_alive{true};
    Queue<uint8_t>& clients_commands_queue;
    MapQueues& map_queues;

    /*
     * Kills dead clients and deletes them.
     * */
    void reap_dead();

    /*
     * Kills all clients threads, deletes them and clears the list of clients.
     * */
    void kill_all_clients();

public:
    AcceptorThread(Socket& skt, Queue<uint8_t>& clients_commands_queue, MapQueues& map_queues);

    /*
     * Executes a loop to accept new clients. For each new client, it creates a new ReceiverThread,
     * starts it, and adds a reference to the client´s queue to the map_queues.
     * The Game class has the ownership of this map_queues.
     * It also assigns an unique id to each client.
     * When the acceptor socket is closed, it stops the loop.
     * */
    void run() override;

    /*
     * Sets the acceptor to be dead and closes the acceptor socket.
     * */
    void kill();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_ACCEPTOR_THREAD_H
