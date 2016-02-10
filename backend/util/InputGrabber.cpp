#include "InputGrabber.h"

InputGrabber *InputGrabber::self = NULL;

InputGrabber::InputGrabber()
{
    QApplication::instance()->installEventFilter(this);

#ifndef NO_SFML
    joyListener = new JoystickListener;
    connect(joyListener, SIGNAL(btnPress(InputEvent)), this, SLOT(press(InputEvent)));
    connect(joyListener, SIGNAL(btnRelease(InputEvent)), this, SLOT(release(InputEvent)));
#endif
}

InputGrabber::~InputGrabber()
{
    QApplication::instance()->removeEventFilter(this);
#ifndef NO_SFML
    delete joyListener;
#endif
}

bool InputGrabber::eventFilter(QObject *object, QEvent *event)
{
    (void) object;
    if (event->type() == QEvent::KeyPress) {

        press(static_cast<QKeyEvent *>(event));

         return true;
    }

    if (event->type() == QEvent::KeyRelease) {

        release(static_cast<QKeyEvent *>(event));

        return true;
    }

    return false;
}

void InputGrabber::press(InputEvent event)
{
    emit inputPress(event);

    for (InputInterface *child : childs)
        child->onPress(event);
}

void InputGrabber::release(InputEvent event)
{
    emit inputRelease(event);

    for (InputInterface *child : childs)
        child->onRelease(event);
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

void InputGrabber::pushedDirection(Direction direction, BikeController *ctrl)
{
    instance()->emitCtrlDir(direction, ctrl);
}
