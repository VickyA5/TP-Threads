
#ifndef THREADS_2024C1_VICKYA5_SERVER_SERVIDOR_H
#define THREADS_2024C1_VICKYA5_SERVER_SERVIDOR_H

#include <string>

#include "server_acceptor.h"
#include "server_monitor_game.h"


class Server {
private:
    Game game;
    std::string service_name;
    //ServerProtocol protocol;
public:
    explicit Server(const char* service_name);
    int run();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_SERVIDOR_H
