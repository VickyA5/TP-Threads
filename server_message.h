
#ifndef THREADS_2024C1_VICKYA5_SERVER_MESSAGE_H
#define THREADS_2024C1_VICKYA5_SERVER_MESSAGE_H

#include <iostream>

class ServerMessage {
private:
    uint8_t type_event;
    uint16_t alive_cnt;

public:
    ServerMessage(uint8_t type, uint16_t alive_cnt);

    /*
     * Returns the type event.
     * */
    uint8_t get_type_event();

    /*
     * Returns the alive count.
     * */
    uint16_t get_alive_cnt();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_MESSAGE_H
