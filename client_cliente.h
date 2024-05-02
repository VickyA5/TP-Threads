
#ifndef THREADS_2024C1_VICKYA5_CLIENT_CLIENTE_H
#define THREADS_2024C1_VICKYA5_CLIENT_CLIENTE_H

#include "client_parser.h"
#include "client_protocol.h"
#include "common_status_printer.h"

#define SALIR "Salir"
#define INVALID_ACTION -1

class Client {
private:
    ClientParser parser;
    ClientProtocol protocol;
    StatusPrinter printer;

    void translate_action(int action, bool read);

public:
    Client(const char* host_name, const char* service_name);

    /*
     * Executes the loop that reads the inputs and delegates to ClientParser the parsing.
     * */
    void run();

};


#endif  // THREADS_2024C1_VICKYA5_CLIENT_CLIENTE_H
