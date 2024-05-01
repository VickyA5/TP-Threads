
#ifndef THREADS_2024C1_VICKYA5_SERVER_RECEIVER_THREAD_H
#define THREADS_2024C1_VICKYA5_SERVER_RECEIVER_THREAD_H

#include "common_socket.h"
#include "server_map_queues.h"
#include "server_queue.h"
#include "server_protocol.h"
#include "server_sender_thread.h"

#define SHUTDOWN 2

class ReceiverThread: public Thread {
private:
    std::atomic<bool> still_alive{true};
    Queue<uint8_t>& clients_commands_queue;
    Socket client_skt;
    SenderThread sender;

public:
    ReceiverThread(Socket skt_peer, Queue<uint8_t>& clients_commands_queue);

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

    /*
     *
     * */
    Queue<ServerMessage>& get_server_msgs_queue();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_RECEIVER_THREAD_H
