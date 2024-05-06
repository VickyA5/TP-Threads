
#ifndef THREADS_2024C1_VICKYA5_MAPQUEUES_H
#define THREADS_2024C1_VICKYA5_MAPQUEUES_H

#include <map>

#include "server_message.h"
#include "server_queue.h"

class MapQueues {
private:
    std::map<size_t, Queue<ServerMessage>*> server_messages;
    std::mutex mtx;

public:
    MapQueues();

    /*
     *
     *
     * */
    void add_new_queue(size_t id_client, Queue<ServerMessage>* new_queue);

    /*
     *
     *
void push_server_message();
     * */

    /*
     *
     * */
    void broadcast(uint16_t alive_cnt, uint8_t last_type_event);

    /*
     *
     * */
    void delete_queue(size_t id_to_delete);
};


#endif  // THREADS_2024C1_VICKYA5_MAPQUEUES_H
