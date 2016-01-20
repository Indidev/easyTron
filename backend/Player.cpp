#include "Player.h"

Player::Player(std::string name, Bike *bike, int keys[], QObject *parent) :
    QObject(parent)
{
    lastKeyinMs = 0;
    this->name = name;
    this->bike = bike;

    if (bike)
        bike->setPlayer(this);

    timer.setSingleShot(true);

    for (int i = 0; i < 4; i++) {
        this->keys[i] = keys[i];
    }

    connect(KeyboardGrabber::instance(), SIGNAL(keyPress(QKeyEvent*)), this, SLOT(changeDirection(QKeyEvent*)));
    connect(&timer, SIGNAL(timeout()), this, SLOT(doChange()));
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

void Player::doChange()
{
    bike->changeDirection((Direction) nextDirection);
    lastKeyinMs = (long) (std::time(0) / 1000);
}


