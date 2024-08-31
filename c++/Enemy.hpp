#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>


class Enemy {
    public:
        Enemy();
        ~Enemy();
        void initEnemy(int x, int y, int i);
        void update();
        int GetX();
        int x;
        int y;
        int i;

};

#endif