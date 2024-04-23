
#include "server_receiver_thread.h"

#define ATTACK 0x03

ReceiverThread::ReceiverThread(Socket& skt) : client_skt(skt) {}


void ReceiverThread::run() {
    ServerProtocol protocol(client_skt);
    uint8_t msg = 0;
    uint8_t pa_que_compile = msg;
    std::cout << pa_que_compile;
    /*
    msg = protocol.receive_msg();
    if (msg == ATTACK)
        // Aca tendria al map de queues y acá agregaria que se
    else
        throw std::runtime_error("The message sent from the client wasn't the expected.");
        */
}

