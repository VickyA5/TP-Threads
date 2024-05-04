
#include "server_sender_thread.h"


SenderThread::SenderThread(Socket& skt, MapQueues& map_queues, size_t an_id) : client_skt(skt),
        connection_alive(true), queues(map_queues), id(an_id) {}

void SenderThread::run() {
    ServerProtocol protocol(client_skt);
    while (connection_alive) {
        // o hace un try_pop y cuando haya algo se envía el status
        ServerMessage message = server_messages.pop();
        protocol.send_status(message);
        connection_alive = not protocol.get_was_closed();
    }
    if (!connection_alive) {
        queues.delete_queue(id);
    }
}

Queue<ServerMessage>& SenderThread::get_server_msgs_queue() {
    return server_messages;
}
