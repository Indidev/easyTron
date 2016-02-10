#ifndef KEYBOARDINTERFACE_H
#define KEYBOARDINTERFACE_H

#include "EasyTronDef.h"
#include "InputEvent.h"

/**
 * @brief The KeyboardInterface class
 * impement this class to register yourself on the keyboard grabber
 */
class InputInterface {
public:
    /**
     * will be called on key-press
     * @param ev key-event
     */
    virtual void onPress(InputEvent event) {(void) event;}

    /**
     * will be called on key-release
     * @param ev key-event
     */
    virtual void onRelease(InputEvent event) {(void) event;}

    /**
     * change direction input
     * @param dir pressed direction
     * @param ctrl controller which sent the signal
     * @param rel whether the change of direction is relative to the bike or not
     */
    virtual void onCtrlDirection(tron::Direction dir, BikeController *ctrl, bool rel = false)
    {(void) dir; (void) ctrl; (void) rel;}

protected:
    InputInterface() {}
};

#endif // KEYBOARDINTERFACE_H
