
#ifndef THREADS_2024C1_VICKYA5_SERVER_RECEIVER_THREAD_H
#define THREADS_2024C1_VICKYA5_SERVER_RECEIVER_THREAD_H

#include "server_sender_thread.h"

#define SHUTDOWN 2
#define ATTACK 0x03

class ReceiverThread: public Thread {
private:
    std::atomic<bool> keep_talking{true};
    std::atomic<bool> connection_alive{true};
    std::atomic<bool> is_alive{true};
    Queue<uint8_t>& clients_commands_queue;
    Socket client_skt;
    SenderThread sender;

public:
    ReceiverThread(Socket skt_peer,
                   Queue<uint8_t>& clients_commands_queue,
                   MapQueues& map_queues,
                   size_t an_id);

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
    bool is_dead();

    /*
     *
     * */
    Queue<ServerMessage>& get_server_msgs_queue();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_RECEIVER_THREAD_H
