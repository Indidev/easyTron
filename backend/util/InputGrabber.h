#ifndef KEYBOARDGRABBER_H
#define KEYBOARDGRABBER_H

#include <QObject>
#include <QApplication>
#include <QKeyEvent>
#include "InputInterface.h"
#include "JoystickListener.h"

//TODO remove this after testing
#include <iostream>
using namespace std;

/**
 * @brief The InputGrabber class
 * Grabs keyboard signals.
 * Can be used in two ways:
 *  * connect via qt and use signals
 *  * implement "InputInterface" and register onto this class
 */
class InputGrabber : public QObject
{
    Q_OBJECT
public:

    /**
     * returns an instance of the keyboard grabber which can be used for signal grabbing via connect
     * @return instance of InputGrabber
     */
    static InputGrabber* instance();

    /**
     * register an item for key-action notifications
     * @param child child to register
     */
    static void registerItem(InputInterface *child);

    /**
     * unregister an item from notifications
     * @param child child to unregister
     */
    static void unregisterItem(InputInterface *child);

signals:
    /**
     * key press event
     * @param event key-event
     */
    void keyPress(QKeyEvent *event);

    /**
     * key release event
     * @param event key-event
     */
    void keyRelease(QKeyEvent *event);

protected:
    InputGrabber();
    ~InputGrabber();

    virtual bool eventFilter(QObject *object, QEvent *event)override;
    static InputGrabber* self;
    QList<InputInterface*> childs;
    JoystickListener *joyListener;

protected slots:
    void padPress(InputEvent event);
    void padRelease(InputEvent event);
};

#endif // KEYBOARDGRABBER_H
