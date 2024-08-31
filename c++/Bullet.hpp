#ifndef BULLET_HPP
#define BULLET_HPP
#include "Enemy.hpp"


class Bullet {
    public:
        Bullet();
        ~Bullet();
        int x;
        int y;
        int i;
        void init(int x, int y, int i);
        void update(std::vector<Enemy> *enemies, std::vector<Bullet> *bullets);
        bool dead;
};

#endif