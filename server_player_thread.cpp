
#include "server_player_thread.h"


PlayerThread::PlayerThread(Socket skt_peer, GameMonitor& the_game) :
        peer(std::move(skt_peer)), game(the_game) {
}

void PlayerThread::run() {
    ReceiverThread receiver(peer, game);
    receiver.start();
    SenderThread sender(peer, game);
    sender.start();
    receiver.join();
    sender.join();
}

void PlayerThread::kill() {
    still_alive = false;
    peer.shutdown(SHUTDOWN);
    peer.close();
}


//REFACTORIZAR
bool PlayerThread::is_still_alive() {
    return true;
}
