#ifndef BIKECONTROLLER_H
#define BIKECONTROLLER_H

#include "EasyTronDef.h"
#include <QString>
#include <iostream>

#include "backend/game/Bike.h"
#include "backend/util/InputGrabber.h"

using std::string;

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
     * get players name
     */
    QString getName();

    /**
     * get players name as std::string
     */
    string getStdName();

protected:
    BikeController(QString playerName = "");

    void changeDirection(tron::Direction direction);
    void turnLeft();
    void turnRight();

    QString name;
};

#endif // BIKECONTROLLER_H
