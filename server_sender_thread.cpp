
#include "server_sender_thread.h"

SenderThread::SenderThread(Socket& skt, MapQueues& map_queues, size_t an_id) : client_skt(skt),
         connection_alive(true), still_alive(true), queues(map_queues), id(an_id) {}

void SenderThread::run() {
    ServerProtocol protocol(client_skt);
    while (connection_alive && still_alive) {
        ServerMessage message = server_messages.pop();
        connection_alive = not protocol.get_was_closed();
        if (connection_alive) {
            //quizas chequear que se envíe solamente cuando hay un mensaje efectivamente
            protocol.send_status(message);
        } else {
            std::cout << "connection alive del sender es false" << std::endl;
            queues.delete_queue(id);
            server_messages.close();
        }
    }
    std::cout << "Sale del while del sender" << std::endl;
    /*
    if (!connection_alive) {
        queues.delete_queue(id);
        server_messages.close();
    } */
}

Queue<ServerMessage>& SenderThread::get_server_msgs_queue() {
    return server_messages;
}

void SenderThread::kill() {
    still_alive = false;
}
