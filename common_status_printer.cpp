
#include "common_status_printer.h"

void StatusPrinter::printStatus(uint8_t type_event, int aliveCount) {
    int deadCount = 5 - aliveCount;
    if (type_event == KILLED) {
        std::cout << "Un enemigo ha muerto. " << aliveCount << " vivo(s) y " << deadCount << " muerto(s)." << std::endl;
    } else if (type_event == REVIVED) {
        std::cout << "Un enemigo ha revivido. " << aliveCount << " vivo(s) y " << deadCount << " muerto(s)." << std::endl;
    } else {
        std::cout << "Evento no reconocido." << std::endl;
    }
}