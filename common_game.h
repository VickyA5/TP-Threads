
#ifndef THREADS_2024C1_VICKYA5_COMMON_GAME_H
#define THREADS_2024C1_VICKYA5_COMMON_GAME_H

#include <array>
#include <iostream>

class Game {
private:
    std::array<bool, 5> enemies;

public:
    Game();

    /*
     * Asesina a un enemigo. Si todos se encontraban muertos, no pasa nada.
     * */
    void killEnemy();

    /*
     * Revive a un enemigo. Si todos se encontraban vivos, no pasa nada.
     * */
    void reviveEnemy();

    /*
     * Devuelve el estado del juego, donde la primera posición del array representa
     * al número de enemigos vivos y la segunda a la cantidad de muertos.
     * */
    int getAliveNumber() const;

};


#endif  // THREADS_2024C1_VICKYA5_COMMON_GAME_H
