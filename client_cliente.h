
#ifndef THREADS_2024C1_VICKYA5_CLIENT_CLIENTE_H
#define THREADS_2024C1_VICKYA5_CLIENT_CLIENTE_H

#include "client_parser.h"

class Client {
private:
    ClientParser parser;

public:
    Client(const char* host_name, const char* service_name);
    void run();
};


#endif  // THREADS_2024C1_VICKYA5_CLIENT_CLIENTE_H
