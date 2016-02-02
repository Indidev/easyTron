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

}

bool InputMapping::isPlayerAction(const InputEvent &event)
{
    return instance()->playerKeys.contains(event);
}

QPair<int, Direction> InputMapping::getPlayerAction(InputEvent &event)
{
    return instance()->playerKeys[event];
}

InputMapping *InputMapping::instance()
{
    if (!self)
        self = new InputMapping;

    return self;
}
