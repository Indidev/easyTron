#include "Player.h"

Player::Player(std::string name, Bike *bike, int keys[])
{
    lastKeyinMs = 0;
    this->name = name;
    this->bike = bike;

    for (int i = 0; i < 4; i++) {
        this->keys[i] = keys[i];
    }

    connect(KeyboardGrabber::instance(), SIGNAL(keyPress(QKeyEvent*)), this, SLOT(changeDirection(QKeyEvent*)));
}

std::string Player::getName()
{
    return name;
}

void Player::changeDirection(QKeyEvent *event)
{
    for (int i = 0; i < 4; i++) {
        if (keys[i] == event->key()) {
            bike->changeDirection((Direction) i);

        }
    }
}


