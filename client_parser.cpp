
#include "client_parser.h"

int ClientParser::parsing(std::string line) {
    int ret = -1;
    if (line == "Atacar") {
        ret = 0;
    } else {
        std::istringstream iss(line);
        std::string command;
        int n;
        iss >> command >> n;
        if (command == LEER)
            ret = n;
    }
    return ret;
}
