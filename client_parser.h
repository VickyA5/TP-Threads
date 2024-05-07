
#ifndef THREADS_2024C1_VICKYA5_CLIENT_PARSER_H
#define THREADS_2024C1_VICKYA5_CLIENT_PARSER_H

#include <iostream>
#include <sstream>
#include <string>

#define ATACAR 0
#define LEER "Leer"

class ClientParser {

public:
    /*
     * Returns 0 if action is Atacar and sets read to false, returns n if action is Leer <n>
     * and sets read to true, and returns -1 if action is invalid.
     * */
    int parsing(std::string linea, bool& read);
};


#endif  // THREADS_2024C1_VICKYA5_CLIENT_PARSER_H
