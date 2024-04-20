
#include "client_parser.h"

void ClientParser::parsing(std::string line) {
    if (line == ATACAR) {
        //logica
        std::cout << "Mensaje recibido: " << line << std::endl;
    } else if (line == SALIR) {
        //logica
        std::cout << "Mensaje recibido: " << line << std::endl;
    } else {
        std::istringstream iss(line);
        std::string command;
        int n;
        iss >> command >> n;
        if (command == "Leer") {
            //logica
            std::cout << "Mensaje recibido: Leer " << n << std::endl;
        } else {
            throw std::runtime_error("Invalid call: " + line);
        }
    }
}
