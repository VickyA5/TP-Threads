
#ifndef THREADS_2024C1_VICKYA5_SERVER_ACCEPTOR_THREAD_H
#define THREADS_2024C1_VICKYA5_SERVER_ACCEPTOR_THREAD_H

#include <algorithm>
#include <iostream>
#include <list>
#include "common_socket.h"
#include "server_map_queues.h"
#include "server_receiver_thread.h"
#include "server_thread.h"

class AcceptorThread : public Thread {
private:
    Socket& listener_skt;
    std::list<ReceiverThread*> clients;
    std::atomic<bool> still_alive{true};
    Queue<uint8_t>& clients_commands_queue;
    MapQueues& map_queues;

    /*
     *
     * */
    void clean_clients();

    /*
     *
     * */
    void kill_all_clients();

public:
     AcceptorThread(Socket& skt, Queue<uint8_t>& clients_commands_queue, MapQueues& map_queues);

    /*
     *
     * */
    void run() override;

    /*
     *
     * */
    void stop_acceptor();

    /*
     *
     * */
    //bool get_still_alive() override;
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_ACCEPTOR_THREAD_H
