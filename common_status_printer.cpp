
#include "common_status_printer.h"

void StatusPrinter::print_status(uint8_t type_event, uint16_t alive_count) {
    int deadCount = TOTAL_ENEMIES - alive_count;
    if (type_event == KILLED) {
        std::cout << "Un enemigo ha muerto. " << alive_count << " vivo(s) y " << deadCount
                  << " muerto(s)." << std::endl;
    } else if (type_event == REVIVED) {
        std::cout << "Un enemigo ha revivido. " << alive_count << " vivo(s) y " << deadCount
                  << " muerto(s)." << std::endl;
    }
}
