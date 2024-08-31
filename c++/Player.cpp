#include <SDL2/SDL.h>
#include "Player.hpp"
#include "BulletManager.hpp"

Player::Player() : playerX(240) {}
Player::~Player() {}

void Player::movePlayer(bool keyboard[], BulletManager* manager) {

    if (keyboard[SDLK_a]) {
        this->playerX -= 4;
    }

    if (keyboard[SDLK_d]) {
        this->playerX += 4;
    }

    if (keyboard[SDLK_SPACE]) {
        if (!this->didShoot) {
            manager->addBullet(this->playerX, 300, manager->bullets.size());
            this->didShoot = true;
        }
    } else {
        this->didShoot = false;
    }

}
