
#include "common_game.h"

Game::Game() : enemies({true, true, true, true, true}) {
}

//Mas adelante tener cuidado con proteger estos recursos, y fijarme si no hay problema
// con tener problema con la posicion de memoria si se me mueve.
void Game::killEnemy() {
    for (bool& enemy : enemies) {
        if (enemy) {
            enemy = false;
            std::cout << "Enemigo asesinado." << std::endl;
            return;
        }
    }
    std::cout << "Todos los enemigos ya están muertos." << std::endl;
}

void Game::reviveEnemy() {
    for (bool& enemy : enemies) {
        if (!enemy) {
            enemy = true;
            std::cout << "Enemigo revivido." << std::endl;
            return;
        }
    }
    std::cout << "Todos los enemigos ya están vivos." << std::endl;
}

int Game::getAliveNumber() const {
    int alive;
    for (bool enemy : enemies) {
        if (enemy)
            alive++;
    }
    return alive;
}
