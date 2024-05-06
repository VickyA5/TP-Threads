
#include "server_sender_thread.h"

SenderThread::SenderThread(Socket& skt, MapQueues& map_queues, size_t an_id):
        client_skt(skt),
        connection_alive(true),
        keep_talking(true),
        queues(map_queues),
        id(an_id) {}

void SenderThread::run() {
    ServerProtocol protocol(client_skt);
    while (connection_alive && keep_talking) {
        try {
            ServerMessage message = server_messages.pop();
            connection_alive = not protocol.get_was_closed();
            if (connection_alive) {
                protocol.send_status(message);
            } else {
                try {
                    queues.delete_queue(id);
                } catch (...) {
                    std::cout << "Catch del while del sender" << std::endl;
                }
            }
        } catch (const std::exception& err) {
            // std::cout << "Catch del pop del sender" << err.what() << std::endl;
        }
    }
}

Queue<ServerMessage>& SenderThread::get_server_msgs_queue() { return server_messages; }

void SenderThread::kill() {
    keep_talking = false;
    try {
        queues.delete_queue(id);
    } catch (...) {
        std::cout << "Catch del kill de sender" << std::endl;
    }
    // queues.delete_queue(id);
    // server_messages.close();
    /*const std::exception& err*/
}
