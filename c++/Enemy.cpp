#include "Enemy.hpp"

Enemy::Enemy() {};
Enemy::~Enemy() {};

void Enemy::initEnemy(int x, int y, int i) {
    this->x = x;
    this->y = y;
    this->i = i;
}

void Enemy::update() {
    this->y += 3;
    if (this->y > 530) {
        this->x = (rand() % 480)+100;
        this->y = (this->i+1) * -600;
    }
}

int Enemy::GetX() {
    return this->x;
}