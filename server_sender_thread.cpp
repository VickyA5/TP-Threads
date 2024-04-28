
#include "server_sender_thread.h"
#include "server_monitor_game.h"


SenderThread::SenderThread(Socket& skt, GameMonitor& the_game) : client_skt(skt), game(the_game){}

void SenderThread::run() {
    //llama al metodo de enviar del protocolo
}
