#include "LocalBikeController.h"

LocalBikeController::LocalBikeController(Bike* bike, int keys[]) :
    BikeController(bike)
{
    for (int i = 0; i < 4; i++) {
        this->keys[i] = InputEvent(keys[i], "", InputEvent::qtInput);
    }

    InputGrabber::registerItem(this);
}

LocalBikeController::LocalBikeController(Bike *bike, InputEvent keys[]) :
    BikeController(bike)
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
