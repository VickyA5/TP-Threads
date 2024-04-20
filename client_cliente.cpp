
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "client_cliente.h"

Client::Client(const char* host_name, const char* service_name) {

}

// Quizas hacer como Abraham que el parser haga el getline y devuelva
// la accion.
void Client::run() {
    std::string line;
    while (std::getline(std::cin, line, '\n')) {
        if (!line.empty()) {
            parser.parsing(line);
        }
    }
}
