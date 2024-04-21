
#ifndef THREADS_2024C1_VICKYA5_SERVER_SERVIDOR_H
#define THREADS_2024C1_VICKYA5_SERVER_SERVIDOR_H

#include "common_game.h"
#include "server_protocol.h"

class Server {
private:
    Game game;
    ServerProtocol protocol;
public:
    explicit Server(const char* service_name);
    int run();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_SERVIDOR_H
