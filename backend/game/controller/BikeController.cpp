#include "BikeController.h"

BikeController::BikeController(QString playerName)
{
    this->name = playerName;
}

QString BikeController::getName()
{
    return name;
}

string BikeController::getStdName()
{
    return name.toStdString();
}

void BikeController::changeDirection(Direction direction)
{
    InputGrabber::pushedDirection(direction, this);
}

void BikeController::turnLeft()
{
    InputGrabber::pushedDirection(tron::left, this, true);
}

void BikeController::turnRight()
{
    InputGrabber::pushedDirection(tron::right, this, true);
}
