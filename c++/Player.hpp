#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "BulletManager.hpp"

class Player {
    public:
        Player();
        ~Player();
        void movePlayer(bool keyboard[], BulletManager* manager);
        int playerX;
        bool didShoot;
};

#endif // MYSDLAPP_HPP
