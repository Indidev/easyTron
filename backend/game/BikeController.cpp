#include "BikeController.h"

BikeController::BikeController(Bike *bike)
{
    this->bike = bike;
}

void BikeController::changeDirection(Direction direction)
{
    bike->changeDirection(direction);
}

void BikeController::turnLeft()
{
    changeDirection((tron::Direction) ((bike->getCurDirection() + 3) % 4));
}

void BikeController::turnRight()
{
    changeDirection((tron::Direction)((bike->getCurDirection() + 1) % 4));
}
