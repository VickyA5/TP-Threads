
#include "server_message.h"

ServerMessage::ServerMessage(uint8_t type, uint16_t alive_cnt) : type_event(type),
        alive_cnt(alive_cnt) {}

uint8_t ServerMessage::get_type_event() {
    return type_event;
}

uint16_t ServerMessage::get_alive_cnt() {
    return alive_cnt;
}
