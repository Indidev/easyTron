#ifndef BIKECONTROLLER_H
#define BIKECONTROLLER_H

#include <QString>

#include "backend/game/Bike.h"

class BikeController
{
public:

    virtual QString toString() = 0;

protected:
    BikeController(Bike* bike);

    void changeDirection(tron::Direction direction);
    void turnLeft();
    void turnRight();

    Bike *bike;
};

#endif // BIKECONTROLLER_H
