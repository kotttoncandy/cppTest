#include "BulletManager.hpp"
#include "Bullet.hpp"
#include <iostream>

BulletManager::BulletManager() {};
BulletManager::~BulletManager() {};

void BulletManager::addBullet(int x, int y, int i) {
    Bullet obj;
    obj.init(x-15, y-15, i);
    this->bullets.push_back(obj);
}