
#include "server_parser.h"

// debe estar leyendo de la entrada estándar a la espera de leer la letra q que le indica que debe
// finalizar cerrando todos los sockets, queues y joinenando todos los threads sin enviar ningún
// mensaje adicional ni imprimir por salida estándar.
int ServerParser::run(Server & server) {
    std::string line;
    int ret = -1;
    ret = server.run();
    std::getline(std::cin, line, '\n');
    if (line == EXIT)
        return 0;
    return ret;
}
