#ifndef BIKECONTROLLER_H
#define BIKECONTROLLER_H

#include "backend/game/Bike.h"

class BikeController
{
public:
    BikeController(Bike* bike);

    void changeDirection(tron::Direction direction);
    void turnLeft();
    void turnRight();

protected:
    Bike *bike;
};

#endif // BIKECONTROLLER_H
