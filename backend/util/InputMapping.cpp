#include "InputMapping.h"

InputMapping *InputMapping::self = NULL;

bool InputMapping::isPlayerAction(const InputEvent &event)
{
    return instance()->playerKeys.contains(event);
}

QPair<int, Direction> InputMapping::getPlayerAction(InputEvent &event)
{
    return instance()->playerKeys[event];
}

InputMapping::InputMapping()
{
    self = this;
}

InputMapping *InputMapping::instance()
{
    if (!self)
        self = new InputMapping;

    return self;
}
