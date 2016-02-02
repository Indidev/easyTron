#ifndef INPUTMAPPING_H
#define INPUTMAPPING_H

#include <QMap>
#include <QPair>

#include "InputEvent.h"
#include "backend/game/Bike.h"

class InputMapping
{
public:
    static bool isPlayerAction(const InputEvent &event);
    static QPair<int, tron::Direction> getPlayerAction(InputEvent &event);

protected:
    InputMapping();

    static InputMapping *self;

    QMap<InputEvent, QPair<int, tron::Direction> > playerKeys;

    static InputMapping *instance();
};

#endif // INPUTMAPPING_H
