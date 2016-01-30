#include "InputGrabber.h"

InputGrabber *InputGrabber::self = NULL;

InputGrabber::InputGrabber()
{
    QApplication::instance()->installEventFilter(this);
    self = NULL;

#ifndef NO_SFML
    joyListener = new JoystickListener;
    connect(joyListener, SIGNAL(btnPress(InputEvent)), this, SLOT(padPress(InputEvent)));
    connect(joyListener, SIGNAL(btnRelease(InputEvent)), this, SLOT(padRelease(InputEvent)));
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
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        emit(keyPress(keyEvent));

        for (InputInterface *child : childs)
            child->onPress(keyEvent);

         return true;
    }

    if (event->type() == QEvent::KeyRelease) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        emit(keyRelease(keyEvent));

        for (InputInterface *child : childs)
            child->onRelease(keyEvent);

        return true;
    }

    return false;
}

void InputGrabber::padPress(InputEvent event)
{
    cout << "Press: " << event.toString().toStdString() << endl;
}

void InputGrabber::padRelease(InputEvent event)
{
    cout << "Release: " << event.toString().toStdString() << endl;
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
