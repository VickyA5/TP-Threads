
#include "server_player_thread.h"


PlayerThread::PlayerThread(Socket skt_peer) :
        peer(std::move(skt_peer)) {
}

void PlayerThread::run() {
    ReceiverThread receiver(peer);
    receiver.start();
    SenderThread sender(peer);
    sender.start();
    receiver.join();
    sender.join();
}

void PlayerThread::kill() {
    still_alive = false;
    peer.shutdown(2);
    peer.close();
}


//REFACTORIZAR
bool PlayerThread::is_still_alive() {
    return true;
}
