
#include <string>
#include <iostream>
#include "client_cliente.h"

Client::Client(const char* host_name, const char* service_name) :
        protocol(host_name, service_name) {}

// Quizas hacer que el parser haga el getline y devuelva la accion.
void Client::run() {
    std::string line;
    int action;
    bool read = false;
    while (std::getline(std::cin, line, '\n')) {
        if (line == SALIR) {
            //cerrar conexion
            return;
        }
        if (!line.empty()) {
            action = parser.parsing(line, read);
            translateAction(action, read);
        }
    }
}

void Client::translateAction(int action, bool read) {
    if (action == INVALID_ACTION) {
        throw std::runtime_error("Error: an invalid action was received");
    } else if (action == ATACAR && !read) {
        protocol.send_msg_attack();
    } else {
        uint8_t  type_event = 0;
        int alive_count;
        for (int i = 0; i < action; ++i) {
            alive_count = protocol.receive_msg(type_event);
            printer.print_status(type_event, alive_count);
        }
    }
}
