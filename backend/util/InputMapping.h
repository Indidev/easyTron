#ifndef INPUTMAPPING_H
#define INPUTMAPPING_H

#include <QMap>
#include <QPair>

#include "InputEvent.h"
#include "backend/game/controller/BikeController.h"
#include "backend/game/controller/LocalBikeController.h"

//todo maybe restructure this class

//todo remove this after testing
#include "JoystickListener.h"

class InputMapping
{
public:
    static BikeController* getController(int num);
    static void init() {instance();}

protected:
    InputMapping();

    static InputMapping *self;

    QList<BikeController *> controllers;

    static InputMapping *instance();
};

#endif // INPUTMAPPING_H
