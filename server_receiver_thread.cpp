
#include "server_receiver_thread.h"

ReceiverThread::ReceiverThread(Socket skt_peer, Queue<uint8_t>& clients_commands_queue,
                               MapQueues& map_queues, size_t an_id):
        clients_commands_queue(clients_commands_queue),
        client_skt(std::move(skt_peer)),
        sender(client_skt, map_queues, an_id) {}

void ReceiverThread::run() {
    ServerProtocol protocol(client_skt);
    sender.start();
    while (connection_alive && keep_talking) {
        uint8_t msg;
        msg = protocol.receive_msg();
        connection_alive = not protocol.get_was_closed();
        if (msg == ATTACK) {
            clients_commands_queue.push(ATTACK);
        }
    }
    is_alive = false;
    sender.kill();
    sender.join();
}

void ReceiverThread::kill() {
    keep_talking = false;
    client_skt.shutdown(SHUTDOWN);
    client_skt.close();
}

Queue<ServerMessage>& ReceiverThread::get_server_msgs_queue() {
    return sender.get_server_msgs_queue();
}

bool ReceiverThread::is_dead() { return not is_alive; }
