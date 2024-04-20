
#ifndef THREADS_2024C1_VICKYA5_CLIENT_PARSER_H
#define THREADS_2024C1_VICKYA5_CLIENT_PARSER_H

#include <string>
#include <iostream>
#include <sstream>

#define ATACAR "Atacar"
#define SALIR "Salir"

class ClientParser {

public:
    bool keepParsing();
    void parsing(std::string linea);
};


#endif  // THREADS_2024C1_VICKYA5_CLIENT_PARSER_H
