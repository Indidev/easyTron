#include "InputEvent.h"

InputEvent::InputEvent(QKeyEvent *event)
{
    inputType = qtInput;
    keyCode = event->key();
    keyName = QKeySequence(event->key()).toString();
    mod = event->modifiers();
}

InputEvent::InputEvent(int key, QString name, InputType type, Qt::KeyboardModifiers modifier)
{
    inputType = type;
    keyCode = key;
    keyName = name;
    mod = modifier;
}

bool InputEvent::operator ==(const InputEvent &other)
{
    return inputType == other.inputType &&
            keyCode == other.keyCode;
}
