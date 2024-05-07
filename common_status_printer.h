

#ifndef THREADS_2024C1_VICKYA5_COMMON_STATE_PRINTER_H
#define THREADS_2024C1_VICKYA5_COMMON_STATE_PRINTER_H

#include <iostream>

#define KILLED 0x04
#define REVIVED 0x05
#define TOTAL_ENEMIES 5

class StatusPrinter {

public:
    /*
     * Prints a text with the type of event received, and the number of alive and dead enemys.
     * */
    void print_status(uint8_t type_event, uint16_t alive_count);
};


#endif  // THREADS_2024C1_VICKYA5_COMMON_STATE_PRINTER_H
