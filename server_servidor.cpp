
#include "server_servidor.h"

Server::Server(const char* service_name) {
    this->service_name = service_name;
}

int Server::run(){

    AcceptorThread acceptor(service_name);
    acceptor.start();
    while (std::cin.get() != 'q') {}
    acceptor.kill();
    acceptor.join();
    /*
    bool connected = true;
    while (connected) {
        protocol.receive_msg(game, &connected);
        if (!connected)
            break;
        protocol.send_status(game);
    }*/
    return 0;
}
