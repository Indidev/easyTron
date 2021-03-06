#include "LocalBikeController.h"

LocalBikeController::LocalBikeController(int keys[4], QString name) :
    BikeController(name)
{
    for (int i = 0; i < 4; i++) {
        this->keys[i] = InputEvent(keys[i], "", InputEvent::qtInput);
    }

    InputGrabber::registerItem(this);
}

LocalBikeController::LocalBikeController(InputEvent keys[], QString name) :
    BikeController(name)
{
    for (int i = 0; i < 4; i++) {
        this->keys[i] = keys[i];
    }

    InputGrabber::registerItem(this);
}

LocalBikeController::~LocalBikeController()
{
    InputGrabber::unregisterItem(this);
}

void LocalBikeController::onPress(InputEvent event)
{
    for (int i = 0; i < 4; i++) {
        if (keys[i] == event) {
            changeDirection((Direction) i);
        }
    }
}

QString LocalBikeController::toString()
{
    return "Up: " + keys[0].toString() + " Down: " + keys[2].toString() +
            " Left: " + keys[3].toString() + " Right: " + keys[1].toString();
}
