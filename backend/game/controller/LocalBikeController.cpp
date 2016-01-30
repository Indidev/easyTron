#include "LocalBikeController.h"

LocalBikeController::LocalBikeController(Bike* bike, int keys[]) :
    BikeController(bike)
{
    for (int i = 0; i < 4; i++) {
        this->keys[i] = keys[i];
    }

    KeyboardGrabber::registerItem(this);
}

LocalBikeController::~LocalBikeController()
{
    KeyboardGrabber::unregisterItem(this);
}

void LocalBikeController::onPress(QKeyEvent *event)
{
    for (int i = 0; i < 4; i++) {
        if (keys[i] == event->key()) {
            changeDirection((Direction) i);
        }
    }
}
