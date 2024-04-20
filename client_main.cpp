
#include <iostream>
#include "client_cliente.h"
#define ERROR -1

int main(int argc, const char* argv[]) {
    try {
        if (argc == 3) {
            Client client(argv[1], argv[2]);
            client.run();
            return 0;
        } else {
            std::cerr << "Invalid arguments, must be entered " << argv[0]
                      << " <hostname> <servername> \n";
            return ERROR;
        }
    } catch (const std::exception& err) {
        std::cerr << "Something went wrong: " << err.what() << "\n";
        return ERROR;
    } catch (...) {
        std::cerr << "Something went wrong and an unknown error was intercepted:\n";
        return ERROR;
    }
}
