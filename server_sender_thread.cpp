
#include "server_sender_thread.h"


SenderThread::SenderThread(Socket& skt) : client_skt(skt) {}

void SenderThread::run() {
    // dentro de un while?
    ServerMessage message = server_messages.pop();
    ServerProtocol protocol(client_skt);
    protocol.send_status(message.get_alive_cnt(), message.get_type_event());

}

Queue<ServerMessage>& SenderThread::get_server_msgs_queue() {
    return server_messages;
}
