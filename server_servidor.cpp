
#include "server_servidor.h"

Server::Server(const char* service_name) : acceptor_skt(service_name) {
}

int Server::run(){

    AcceptorThread acceptor(acceptor_skt);
    acceptor.start();
    Gameloop gameloop;
    gameloop.start();
    while (std::cin.get() != EXIT) {}
    gameloop.stop_loop();
    acceptor_skt.shutdown(2);
    acceptor_skt.close();
    acceptor.join();
    gameloop.join();

    return 0;
}
