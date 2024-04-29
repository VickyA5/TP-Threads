
#ifndef THREADS_2024C1_VICKYA5_CLIENT_PARSER_H
#define THREADS_2024C1_VICKYA5_CLIENT_PARSER_H

#include <string>
#include <iostream>
#include <sstream>

#define ATACAR 0
#define LEER "Leer"

class ClientParser {

public:
    //bool keepParsing();

    /*
     * Returns 0 if action is Atacar, n if action is Leer <n>, and -1 if action is invalid.
     * */
    int parsing(std::string linea, bool& read);
};


#endif  // THREADS_2024C1_VICKYA5_CLIENT_PARSER_H
