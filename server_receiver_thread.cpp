
#include "server_receiver_thread.h"

ReceiverThread::ReceiverThread(Socket skt_peer, Queue<uint8_t>& clients_commands_queue) :
         clients_commands_queue(clients_commands_queue), client_skt(std::move(skt_peer)),
        sender(client_skt) {
}

// REVISAR EL ORDEN EN QUE HAGO LAS COSAS
void ReceiverThread::run() {
    ServerProtocol protocol(client_skt);
    uint8_t msg = 0;
    sender.start();
    while (connection_alive) {
        msg = protocol.receive_msg();
        connection_alive = protocol.get_was_closed();
        if (msg == ATTACK) {
            clients_commands_queue.push(ATTACK);
        } else {
            throw std::runtime_error("The message sent from the client wasn't the expected.");
        }
    }
    sender.join();
}

void ReceiverThread::kill() {
    still_alive = false;
    client_skt.shutdown(SHUTDOWN);
    client_skt.close();
}

Queue<ServerMessage>& ReceiverThread::get_server_msgs_queue() {
    return sender.get_server_msgs_queue();
}

//REFACTORIZAR
bool ReceiverThread::is_still_alive() {
    return true;
}
