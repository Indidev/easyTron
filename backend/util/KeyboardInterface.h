#ifndef KEYBOARDINTERFACE_H
#define KEYBOARDINTERFACE_H

#include <QKeyEvent>

/**
 * @brief The KeyboardInterface class
 * impement this class to register yourself on the keyboard grabber
 */
class KeyboardInterface {
public:
    /**
     * will be called on key-press
     * @param ev key-event
     */
    virtual void onPress(QKeyEvent *event) {(void) event;}

    /**
     * will be called on key-release
     * @param ev key-event
     */
    virtual void onRelease(QKeyEvent *event) {(void) event;}

protected:
    KeyboardInterface() {}
};

#endif // KEYBOARDINTERFACE_H
