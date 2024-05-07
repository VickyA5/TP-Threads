
#ifndef THREADS_2024C1_VICKYA5_SERVER_ENEMY_H
#define THREADS_2024C1_VICKYA5_SERVER_ENEMY_H

#include "server_thread.h"

#define ITERATIONS_REQUIRED_TO_REVIVE 15

class Enemy {
private:
    std::atomic<bool> alive{true};
    std::atomic<int> iterations{0};

public:
    /*
     * If the enemy is already dead, returns false. If the enemy is alive, returns true and kills
     * the enemy.
     * */
    bool kill();

    /*
     * If the enemy was dead and has waited 15 iterations it is revived, and returns true.
     * If the enemy can't be revived because it is alive, returns false. Iterations doesn't matter.
     * If the enemy can't be revived because it is dead but hasn't waited 15 iterations, returns
     * false because it was not revived.
     * Every time an enemy can't be revived, iterations increase by 1.
     * */
    bool try_revive();

    /*
     * Returns true if the enemy is alive, false if not.
     * */
    bool is_alive();
};


#endif  // THREADS_2024C1_VICKYA5_SERVER_ENEMY_H
