#ifndef KEYBOARDINTERFACE_H
#define KEYBOARDINTERFACE_H

#include <QKeyEvent>

class KeyboardInterface {
public:
    virtual void onPress(QKeyEvent *ev) = 0;
    virtual void onRelease(QKeyEvent *ev) = 0;
};

#endif // KEYBOARDINTERFACE_H
