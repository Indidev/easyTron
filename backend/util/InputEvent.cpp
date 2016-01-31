#include "InputEvent.h"

InputEvent::InputEvent(QKeyEvent *event)
{
    inputType = qtInput;
    keyCode = event->key();
    keyName = QKeySequence(event->key()).toString();
    mod = event->modifiers();
}

InputEvent::InputEvent(int joyStickKey, QString name)
{
    inputType = joyInput;
    keyCode = joyStickKey;
    keyName = name;
    mod = Qt::NoModifier;
}

bool InputEvent::operator ==(const InputEvent &other)
{
    return inputType == other.inputType &&
            keyCode == other.keyCode;
}
