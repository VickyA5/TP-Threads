
#include "server_sender_thread.h"


SenderThread::SenderThread(Socket& skt) : client_skt(skt), connection_alive(true) {}

void SenderThread::run() {
    ServerProtocol protocol(client_skt);
    while (connection_alive) {
        // o hace un try_pop y cuando haya algo se envía el status
        ServerMessage message = server_messages.pop();
        protocol.send_status(message.get_alive_cnt(), message.get_type_event());
        connection_alive = not protocol.get_was_closed();
    }
}

Queue<ServerMessage>& SenderThread::get_server_msgs_queue() {
    return server_messages;
}
