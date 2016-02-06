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
    static bool isPlayerAction(const InputEvent &event);
    static QPair<int, tron::Direction> getPlayerAction(InputEvent &event);
    static BikeController* getController(InputEvent &event);

protected:
    InputMapping();

    static InputMapping *self;

    QMap<InputEvent, QPair<int, tron::Direction> > playerKeys;
    QMap<InputEvent, BikeController*> controllerMap;

    static InputMapping *instance();
};

#endif // INPUTMAPPING_H
