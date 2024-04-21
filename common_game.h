
#ifndef THREADS_2024C1_VICKYA5_COMMON_GAME_H
#define THREADS_2024C1_VICKYA5_COMMON_GAME_H

#include <array>
#include <iostream>

#define KILLED 0x04
#define REVIVED 0x05

class Game {
private:
    std::array<bool, 5> enemies;
    //QUE PASA SI EL CLIENTE QUIERE LEER SIN QUE HAYA MUERTO NADIE
    uint8_t last_type_event;

public:
    Game();

    /*
     * Asesina a un enemigo. Si todos se encontraban muertos, no pasa nada.
     * */
    void kill_enemy();

    /*
     * Revive a un enemigo. Si todos se encontraban vivos, no pasa nada.
     * */
    void revive_enemy();

    /*
     * Devuelve el estado del juego, donde la primera posición del array representa
     * al número de enemigos vivos y la segunda a la cantidad de muertos.
     * */
    int get_alive_cnt() const;

    /*
     *
     * */
    uint8_t get_last_type_event();

};


#endif  // THREADS_2024C1_VICKYA5_COMMON_GAME_H
