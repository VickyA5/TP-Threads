
#ifndef THREADS_2024C1_VICKYA5_SERVER_SENDER_THREAD_H
#define THREADS_2024C1_VICKYA5_SERVER_SENDER_THREAD_H

#include "server_map_queues_monitor.h"
#include "server_message.h"
#include "server_protocol.h"
#include "server_queue.h"
#include "server_thread.h"

class SenderThread: public Thread {
private:
    Socket& client_skt;
    Queue<ServerMessage> server_messages;
    std::atomic<bool> connection_alive;
    std::atomic<bool> keep_talking;
    MapQueues& queues;
    size_t id;

public:
    SenderThread(Socket& skt, MapQueues& map_queues, size_t an_id);

    /*
     * Executes the loop that sends the status of the game to a client. It pop´s the status from
     * the game´s queue.
     * */
    void run() override;

    /*
     * Returns a reference to the server message queue.
     * */
    Queue<ServerMessage>& get_server_msgs_queue();

    /*
     * Sets keep_talking to false in order to tell the run() method to stop iterating. Also, it
     * deletes the queue from the Map based on its id.
     * */
    void kill();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_SENDER_THREAD_H
