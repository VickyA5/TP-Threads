
#include <exception>
#include <iostream>
#include "server_servidor.h"
#include "server_parser.h"

#define ERROR (-1)

int main(int argc, char* argv[]) {
    try {
        int ret = ERROR;
        if (argc == 2) {
            Server server(argv[1]);
            ServerParser serverParser;
            ret = serverParser.run(server);
        } else {
            std::cerr << "Invalid arguments, must be entered " << argv[0]
                      << " <hostname> <servername> \n";
            return ret;
        }
        return ret;
    } catch (const std::exception& err) {
        std::cerr << "Something went wrong: " << err.what() << "\n";
        return ERROR;
    } catch (...) {
        std::cerr << "Something went wrong and an unknown error was intercepted:\n";
        return ERROR;
    }
}
