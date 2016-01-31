#ifndef INPUTEVENT_H
#define INPUTEVENT_H

#include <QKeyEvent>
#include <QString>

class InputEvent
{
public:
    /**
     * creates a new Input event for a QKeyEvent
     * @param event qkeyevent
     */
    InputEvent(QKeyEvent *event);

    /**
     * creates a new Input event for a Joystick
     * @param joyStickKey
     */
    InputEvent(int joyStickKey, QString name);

    /**
     * enum for input type
     */
    enum InputType{qtInput, joyInput};

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

    bool operator ==(const InputEvent &other);
    bool operator !=(const InputEvent &other) {return !(*this==other);}

protected:
    InputType inputType;
    int keyCode;
    QString keyName;
    Qt::KeyboardModifiers mod;

};

#endif // INPUTEVENT_H
