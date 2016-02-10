#ifndef INPUTEVENT_H
#define INPUTEVENT_H

#include "EasyTronDef.h"

#include <QKeyEvent>
#include <QString>

class InputEvent
{
public:

    /**
     * enum for input type
     */
    enum InputType{qtInput, joyInput};

    /**
     * creates a new Input event for a QKeyEvent
     * @param event qkeyevent
     */
    InputEvent(QKeyEvent *event);

    /**
     * creates a new Input event
     * @param key key code
     * @param name name name of the key
     * @param type joyInput (default) | qtInput
     * @param modifier keyboard modifiers
     */
    InputEvent(int key = 0, QString name = "", InputType type = joyInput, Qt::KeyboardModifiers modifier = Qt::NoModifier);

    /**
     * returns the key-code of this event
     * @return keycode
     */
    int key() {return keyCode;}

    /**
     * @return keyboard modifiers
     */
    Qt::KeyboardModifiers modifiers() {return mod;}

    /**
     * @return name of the key
     */
    QString toString() {return keyName;}

    /**
     * @return input type
     */
    InputType type() {return inputType;}

    bool operator == (const InputEvent &rhs) const;
    bool operator != (const InputEvent &rhs) const {return !(*this==rhs);}
    bool operator < (const InputEvent &rhs) const;

protected:
    InputType inputType;
    int keyCode;
    QString keyName;
    Qt::KeyboardModifiers mod;

};

#endif // INPUTEVENT_H
