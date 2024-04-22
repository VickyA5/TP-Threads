
#include "server_acceptor.h"

AcceptorThread::AcceptorThread(std::string& service_name) :
        listener_skt(Socket(service_name.c_str())) {}

void AcceptorThread::run() {
    GameMonitor game;
    // while ()
    // aceptar al nuevo cliente
    // limpiar clientes muertos
}

