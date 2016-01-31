#ifndef KEYBOARDINTERFACE_H
#define KEYBOARDINTERFACE_H

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

protected:
    InputInterface() {}
};

#endif // KEYBOARDINTERFACE_H
