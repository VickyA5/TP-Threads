
#include "client_cliente.h"

#include <iostream>
#include <string>

Client::Client(const char* host_name, const char* service_name):
        protocol(host_name, service_name) {}

void Client::run() {
    std::string line;
    int action;
    bool read = false;
    while (std::getline(std::cin, line, '\n')) {
        if (line == SALIR) {
            protocol.close_connection();
            return;
        }
        if (!line.empty()) {
            action = parser.parsing(line, read);
            translate_action(action, read);
        }
    }
}

void Client::translate_action(int action, bool read) {
    if (action == INVALID_ACTION) {
        throw std::runtime_error("Error: an invalid action was received.");
    } else if (action == ATACAR && !read) {
        protocol.send_msg_attack();
    } else {
        uint8_t type_event = 0;
        for (int i = 0; i < action; ++i) {
            uint16_t alive_count = protocol.receive_msg(type_event);
            printer.print_status(type_event, alive_count);
        }
    }
}
