
#include "server_servidor.h"

Server::Server(const char* service_name) :
        protocol(service_name){}

int Server::run(){
    bool connected = true;
    while (connected) {
        protocol.receive_msg(game, &connected);
        if (!connected)
            break;
        protocol.send_status(game);
    }
    return 0;
}
