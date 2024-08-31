#ifndef ENEMYHANDLER_HPP
#define ENEMYHANDLER_HPP

#include "Enemy.hpp"
#include <iostream>
#include <vector>  // Include this to use std::vector

class EnemyHandler {
    public:
        EnemyHandler();
        ~EnemyHandler();
        std::vector<Enemy> enemies;
        void addEnemy(int x, int y, int i);

};

#endif