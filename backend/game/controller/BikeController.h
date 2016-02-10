#ifndef BIKECONTROLLER_H
#define BIKECONTROLLER_H

#include <QString>

#include "backend/game/Bike.h"
#include "backend/util/InputGrabber.h"

/**
 * abstract class for bike controllers, subclasses are implementing local,
 * as well as network based controllers
 */
class BikeController
{
public: //todo uncouple from bike

    /**
     * get the controlls as a string
     * @return controlls as string
     */
    virtual QString toString() = 0;

    /**
     * sets the bike which should be controlled
     * @param bike bike
     */
    void setBike(Bike* bike);

    /**
     * remove the controllers bike (doesn't delete it!)
     */
    void removeBike();

    /**
     * get players name
     */
    QString getName();

protected:
    BikeController(QString playerName = "", Bike* bike = NULL);

    void changeDirection(tron::Direction direction);
    void turnLeft();
    void turnRight();

    Bike *bike;
    QString name;
};

#endif // BIKECONTROLLER_H
