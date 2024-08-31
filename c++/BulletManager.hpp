#ifndef BULLETMANAGER_HPP
#define BULLETMANAGER_HPP

#include "Bullet.hpp"
#include <iostream>
#include <vector>  // Include this to use std::vector

class BulletManager {
    public:
        BulletManager();
        ~BulletManager();
        std::vector<Bullet> bullets;
        void addBullet(int x, int y, int i);

};

#endif