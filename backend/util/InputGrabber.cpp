#include "InputGrabber.h"

InputGrabber *InputGrabber::self = NULL;

InputGrabber::InputGrabber()
{
    QApplication::instance()->installEventFilter(this);
    self = NULL;
}

InputGrabber::~InputGrabber()
{
    QApplication::instance()->removeEventFilter(this);
}

bool InputGrabber::eventFilter(QObject *object, QEvent *event)
{
    (void) object;
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        //TODO remove this after testing
        cerr << "Key pressed: " << QKeySequence(keyEvent->key()).toString().toStdString() << endl;

        emit(keyPress(keyEvent));

        for (InputInterface *child : childs)
            child->onPress(keyEvent);

         return true;
    }

    if (event->type() == QEvent::KeyRelease) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        //TODO remove this after testing
        cerr << "Key released: " << QKeySequence(keyEvent->key()).toString().toStdString() << endl;

        emit(keyRelease(keyEvent));

        for (InputInterface *child : childs)
            child->onRelease(keyEvent);

        return true;
    }

        return false;
}

InputGrabber *InputGrabber::instance()
{
    if (!self)
        self = new InputGrabber;

    return self;
}

void InputGrabber::registerItem(InputInterface *child)
{
    if (!instance()->childs.contains(child))
        instance()->childs.append(child);
}

void InputGrabber::unregisterItem(InputInterface *child)
{
    instance()->childs.removeAll(child);
}
