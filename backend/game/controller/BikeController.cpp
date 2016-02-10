#include "BikeController.h"

BikeController::BikeController(QString playerName, Bike *bike)
{
    this->name = playerName;
    setBike(bike);
}

void BikeController::setBike(Bike *bike)
{
    this->bike = bike;
    if (bike)
        bike->setName(name.toStdString());
}

void BikeController::removeBike()
{
    this->bike = NULL;
}

QString BikeController::getName()
{
    return name;
}

void BikeController::changeDirection(Direction direction)
{
    if (bike)
        bike->changeDirection(direction);

    InputGrabber::pushedDirection(direction, this);
}

void BikeController::turnLeft()
{
    if (bike)
        changeDirection((tron::Direction) ((bike->getCurDirection() + 3) % 4));
}

void BikeController::turnRight()
{
    if (bike)
        changeDirection((tron::Direction)((bike->getCurDirection() + 1) % 4));
}
