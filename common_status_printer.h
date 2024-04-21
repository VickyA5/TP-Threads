

#ifndef THREADS_2024C1_VICKYA5_COMMON_STATE_PRINTER_H
#define THREADS_2024C1_VICKYA5_COMMON_STATE_PRINTER_H

#include <iostream>

#define KILLED 0x04
#define REVIVED 0x05

class StatusPrinter {

public:
    void printStatus(uint8_t type_event, int aliveCount);
};


#endif  // THREADS_2024C1_VICKYA5_COMMON_STATE_PRINTER_H
