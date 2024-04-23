
#include "server_sender_thread.h"


SenderThread::SenderThread(Socket& skt) : client_skt(skt){}

void SenderThread::run() {
    //llama al metodo de enviar del protocolo
}
