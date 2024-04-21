
#include <string>
#include <iostream>
#include "client_cliente.h"

Client::Client(const char* host_name, const char* service_name) :
        protocol(host_name, service_name) {}

// Quizas hacer que el parser haga el getline y devuelva la accion.
void Client::run() {
    std::string line;
    int action;
    while (std::getline(std::cin, line, '\n')) {
        if (line == SALIR) {
            //cerrar conexion
            break;
        }
        //No se si haga falta chequear linea vacia para los tests privados
        action = parser.parsing(line);
        translateAction(action);
    }
}

void Client::translateAction(int action) {
    if (action == INVALID_ACTION) {
        //FIJARME SI LOS THROW NO MOLESTAN
        throw std::runtime_error("Error: an invalid action was received");
    } else if (action == ATACAR) {
        protocol.send_msg_attack();
    } else {
        uint8_t  type_event = 0;
        int alive_count = 0;
        for (int i = 0; i < action; ++i) {
            alive_count = protocol.receive_msg(type_event);
            printer.printStatus(type_event, alive_count);
        }
    }
}
