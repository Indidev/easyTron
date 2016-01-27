#include "KeyboardGrabber.h"

KeyboardGrabber *KeyboardGrabber::self = NULL;

KeyboardGrabber::KeyboardGrabber()
{
    QApplication::instance()->installEventFilter(this);
    self = NULL;
}

KeyboardGrabber::~KeyboardGrabber()
{
    QApplication::instance()->removeEventFilter(this);
}

bool KeyboardGrabber::eventFilter(QObject *object, QEvent *event)
{
    (void) object;
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        emit(keyPress(keyEvent));

        for (KeyboardInterface *child : childs)
            child->onPress(keyEvent);

         return true;
    }

    if (event->type() == QEvent::KeyRelease) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        emit(keyRelease(keyEvent));

        for (KeyboardInterface *child : childs)
            child->onRelease(keyEvent);

        return true;
    }

        return false;
}

KeyboardGrabber *KeyboardGrabber::instance()
{
    if (!self)
        self = new KeyboardGrabber;

    return self;
}

void KeyboardGrabber::registerItem(KeyboardInterface *child)
{
    if (!instance()->childs.contains(child))
        instance()->childs.append(child);
}

void KeyboardGrabber::unregisterItem(KeyboardInterface *child)
{
    instance()->childs.removeAll(child);
}
