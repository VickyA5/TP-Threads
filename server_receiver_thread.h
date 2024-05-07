
#ifndef THREADS_2024C1_VICKYA5_SERVER_RECEIVER_THREAD_H
#define THREADS_2024C1_VICKYA5_SERVER_RECEIVER_THREAD_H

#include <utility>

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
    ReceiverThread(Socket skt_peer, Queue<uint8_t>& clients_commands_queue, MapQueues& map_queues,
                   size_t an_id);

    /*
     * Executes the loop that receives the messages from a client and pushes the commands to the
     * game´s queue. It also starts the sender thread and then joins it.
     * */
    void run() override;

    /*
     * Sets keep_talking to false in order to tell the method run() to stop and closes the socket.
     * */
    void kill();

    /*
     * Returns true if the thread is not executing the loop.
     * */
    bool is_dead();

    /*
     * Returns a reference to the server message queue.
     * */
    Queue<ServerMessage>& get_server_msgs_queue();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_RECEIVER_THREAD_H
