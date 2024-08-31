#include "EnemyHandler.hpp"
#include "Enemy.hpp"

EnemyHandler::EnemyHandler() {};
EnemyHandler::~EnemyHandler() {};

void EnemyHandler::addEnemy(int x, int y, int i) {
    Enemy obj;
    obj.initEnemy(x, y, i);
    this->enemies.push_back(obj);
}