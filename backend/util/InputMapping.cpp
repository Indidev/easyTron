#include "InputMapping.h"

InputMapping *InputMapping::self = NULL;

InputMapping::InputMapping()
{
    self = this;

    //todo load from file instead of hard-coded
    playerKeys[InputEvent(Qt::Key_Up, "Up", InputEvent::qtInput)] = QPair<int, Direction>(0, tron::up);
    playerKeys[InputEvent(Qt::Key_Down, "Down", InputEvent::qtInput)] = QPair<int, Direction>(0, tron::down);
    playerKeys[InputEvent(Qt::Key_Left, "Left", InputEvent::qtInput)] = QPair<int, Direction>(0, tron::left);
    playerKeys[InputEvent(Qt::Key_Right, "Right", InputEvent::qtInput)] = QPair<int, Direction>(0, tron::right);

    playerKeys[InputEvent(-JoystickListener::Y_AXIS_MASK)] = QPair<int, Direction>(1, tron::up);
    playerKeys[InputEvent(JoystickListener::Y_AXIS_MASK)] = QPair<int, Direction>(1, tron::down);
    playerKeys[InputEvent(-JoystickListener::X_AXIS_MASK)] = QPair<int, Direction>(1, tron::left);
    playerKeys[InputEvent(JoystickListener::X_AXIS_MASK)] = QPair<int, Direction>(1, tron::right);

    playerKeys[InputEvent(Qt::Key_W, "W", InputEvent::qtInput)] = QPair<int, Direction>(0, tron::up);
    playerKeys[InputEvent(Qt::Key_S, "S", InputEvent::qtInput)] = QPair<int, Direction>(0, tron::down);
    playerKeys[InputEvent(Qt::Key_A, "A", InputEvent::qtInput)] = QPair<int, Direction>(0, tron::left);
    playerKeys[InputEvent(Qt::Key_D, "D", InputEvent::qtInput)] = QPair<int, Direction>(0, tron::right);

    //load local controller... TODO!!!
    //quickfix!!!
    InputEvent keys[] = {InputEvent(Qt::Key_Up, "Up", InputEvent::qtInput), InputEvent(Qt::Key_Right, "Right", InputEvent::qtInput),
                         InputEvent(Qt::Key_Down, "Down", InputEvent::qtInput), InputEvent(Qt::Key_Left, "Left", InputEvent::qtInput)};
    BikeController *c1 = new LocalBikeController(keys, "Player 1");

    for (InputEvent k : keys) {
        controllerMap[k] = c1;
    }

    InputEvent iE[] = {InputEvent(-JoystickListener::Y_AXIS_MASK), InputEvent(JoystickListener::X_AXIS_MASK),
                       InputEvent(JoystickListener::Y_AXIS_MASK), InputEvent(-JoystickListener::X_AXIS_MASK)};
    BikeController *c2 = new LocalBikeController(iE, "Player 2");

    for (InputEvent k : iE) {
        controllerMap[k] = c2;
    }

    InputEvent keys2[] = {InputEvent(Qt::Key_W, "W", InputEvent::qtInput), InputEvent(Qt::Key_D, "D", InputEvent::qtInput),
                         InputEvent(Qt::Key_S, "S", InputEvent::qtInput), InputEvent(Qt::Key_A, "A", InputEvent::qtInput)};
    BikeController *c3 = new LocalBikeController(keys2, "Player 3");

    for (InputEvent k : keys2) {
        controllerMap[k] = c3;
    }

}

bool InputMapping::isPlayerAction(const InputEvent &event)
{
    return instance()->playerKeys.contains(event);
}

QPair<int, Direction> InputMapping::getPlayerAction(InputEvent &event)
{
    return instance()->playerKeys[event];
}

BikeController *InputMapping::getController(InputEvent &event)
{
    return instance()->controllerMap[event];
}

InputMapping *InputMapping::instance()
{
    if (!self)
        self = new InputMapping;

    return self;
}
