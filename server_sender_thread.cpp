
#include "server_sender_thread.h"

SenderThread::SenderThread(Socket& skt, MapQueues& map_queues, size_t an_id) : client_skt(skt),
         connection_alive(true), keep_talking(true), queues(map_queues), id(an_id) {}

void SenderThread::run() {
    ServerProtocol protocol(client_skt);
    while (connection_alive && keep_talking) {
        ServerMessage message = server_messages.pop();
        connection_alive = not protocol.get_was_closed();
        if (connection_alive) {
            protocol.send_status(message);
        } else {
            try {
                //ADENTRO ME ESTARIA FALTANDO CATCHEAR EL MISMO ERROR NO?
                queues.delete_queue(id);
            } catch (/*const std::exception& err*/ ...) {
                //std::cout << "El error que dijo tomi" << err.what() << std::endl;
            }

            //server_messages.close();
        }
    }
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
    try {
        keep_talking = false;
        server_messages.close();
    } catch (/*const std::exception& err*/ ...) {
        //std::cout << "El error que dijo tomi" << err.what() << std::endl;
    }

}
