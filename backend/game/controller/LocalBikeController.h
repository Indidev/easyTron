#ifndef LOCALBIKECONTROLLER_H
#define LOCALBIKECONTROLLER_H

#include <QKeyEvent>

#include "BikeController.h"
#include "backend/util/InputInterface.h"
#include "backend/util/InputGrabber.h"
#include "backend/util/InputEvent.h"

/**
 * class used for local control of the bike (keyboard- / joypad-inputs)
 */
class LocalBikeController : public BikeController, public InputInterface
{

public:
    /**
     * constructs a new local controller
     * @param bike bike which should be controlled
     * @param keys keys for control (up, right, down, left)
     */
    LocalBikeController(Bike* bike, int keys[4]);

    /**
     * constructs a new local controller
     * @param bike bike which should be controlled
     * @param keys keys for control (up, right, down, left)
     */
    LocalBikeController(Bike* bike, InputEvent keys[4]);
    ~LocalBikeController();

    /**
     * see KeyboardInterface
     */
    void onPress(InputEvent event);

    /**
     * see BikeController
     */
    QString toString();

protected:
    InputEvent keys[4];

};

#endif // LOCALBIKECONTROLLER_H
