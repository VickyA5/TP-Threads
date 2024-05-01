
#ifndef THREADS_2024C1_VICKYA5_SERVER_SENDER_THREAD_H
#define THREADS_2024C1_VICKYA5_SERVER_SENDER_THREAD_H

#include "server_thread.h"
#include "server_queue.h"
#include "server_message.h"
#include "server_protocol.h"

class SenderThread : public Thread {
private:
    Socket& client_skt;
    Queue<ServerMessage> server_messages;
    bool connection_alive;

public:
    explicit SenderThread(Socket& skt);

    /*
     *
     * */
    void run() override;

    /*
     *
     * */
    Queue<ServerMessage>& get_server_msgs_queue();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_SENDER_THREAD_H
