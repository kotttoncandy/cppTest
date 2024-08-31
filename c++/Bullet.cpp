#include "Bullet.hpp"
#include <vector>
#include "Enemy.hpp"
#include <iostream>

Bullet::Bullet() {};
Bullet::~Bullet() {this->dead = true;};

struct AABB {
    float xMin, yMin;  // Minimum corner (bottom-left)
    float xMax, yMax;  // Maximum corner (top-right)
};

bool checkCollision(const AABB& box1, const AABB& box2) {
    if (box1.xMax < box2.xMin || box2.xMax < box1.xMin) {
        return false;
    }

    if (box1.yMax < box2.yMin || box2.yMax < box1.yMin) {
        return false;
    }

    return true; // Boxes are colliding
}

void Bullet::init(int x, int y, int i) {
    this->x = x;
    this->y = y;
    this->i = i;
}

void Bullet::update(std::vector<Enemy> *enemies, std::vector<Bullet> *bullets) {
    if (this->dead) {
        return;
    }

    this->y -= 2;

    for (int i = 0; i < enemies->size(); i++) {
        AABB box1 = {this->x, this->y, this->x+30, this->y+30}; // AABB with bottom-left (0,0) and top-right (5,5)
        AABB box2 = {enemies->at(i).x, enemies->at(i).y, enemies->at(i).x+50, enemies->at(i).y+50}; // AABB with bottom-left (0,0) and top-right (5,5)
        if (checkCollision(box1, box2)) {
            enemies->at(i).y = 480;
            bullets->erase(bullets->begin() + this->i);
            this->~Bullet();
        }
    }

    if (this->y <= 0 ) {
        bullets->erase(bullets->begin() + this->i);
        this->~Bullet();

    }


}