#include "BikeController.h"

BikeController::BikeController(Bike *bike)
{
    this->bike = bike;
}

void BikeController::setBike(Bike *bike)
{
    this->bike = bike;
}

void BikeController::removeBike()
{
    this->bike = NULL;
}

void BikeController::changeDirection(Direction direction)
{
    if (bike)
        bike->changeDirection(direction);
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
