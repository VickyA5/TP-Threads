
#include "server_enemy.h"

bool Enemy::kill() {
    if (alive) {
        alive = false;
        return true;
    } else {
        return false;
    }
}

bool Enemy::try_revive() {
    if (alive) {
        return false;
    } else {
        iterations++;
        if (iterations == ITERATIONS_REQUIRED_TO_REVIVE) {
            alive = true;
            return true;
        } else {
            return false;
        }
    }
}

bool Enemy::is_alive() {
    return alive;
}
