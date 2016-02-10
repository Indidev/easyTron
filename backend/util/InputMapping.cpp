#include "InputMapping.h"

InputMapping *InputMapping::self = NULL;

InputMapping::InputMapping()
{
    self = this;

    //load local controller... TODO!!!
    //quickfix!!!
    InputEvent keys[] = {InputEvent(Qt::Key_Up, "Up", InputEvent::qtInput), InputEvent(Qt::Key_Right, "Right", InputEvent::qtInput),
                         InputEvent(Qt::Key_Down, "Down", InputEvent::qtInput), InputEvent(Qt::Key_Left, "Left", InputEvent::qtInput)};

    controllers.append(new LocalBikeController(keys, "Player 1"));

    InputEvent iE[] = {InputEvent(-JoystickListener::Y_AXIS_MASK), InputEvent(JoystickListener::X_AXIS_MASK),
                       InputEvent(JoystickListener::Y_AXIS_MASK), InputEvent(-JoystickListener::X_AXIS_MASK)};

    controllers.append(new LocalBikeController(iE, "Player 2"));


    InputEvent keys2[] = {InputEvent(Qt::Key_W, "W", InputEvent::qtInput), InputEvent(Qt::Key_D, "D", InputEvent::qtInput),
                         InputEvent(Qt::Key_S, "S", InputEvent::qtInput), InputEvent(Qt::Key_A, "A", InputEvent::qtInput)};

    controllers.append(new LocalBikeController(keys2, "Player 3"));
}

BikeController *InputMapping::getController(int num)
{
    if (num >= instance()->controllers.size())
        return NULL;

    return instance()->controllers[num];
}

InputMapping *InputMapping::instance()
{
    if (!self)
        self = new InputMapping;

    return self;
}
