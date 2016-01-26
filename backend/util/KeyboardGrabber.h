#ifndef KEYBOARDGRABBER_H
#define KEYBOARDGRABBER_H

#include <QObject>
#include <QApplication>
#include <QKeyEvent>
#include "KeyboardInterface.h"

/**
 * @brief The KeyboardGrabber class
 * Grabs keyboard signals.
 * Can be used in two ways:
 *  * connect via qt and use signals
 *  * implement "KeyboardInterface" and register onto this class
 */
class KeyboardGrabber : public QObject
{
    Q_OBJECT
public:

    /**
     * returns an instance of the keyboard grabber which can be used for signal grabbing via connect
     * @return instance of KeyboardGrabber
     */
    static KeyboardGrabber* instance();

    /**
     * register an item for key-action notifications
     * @param child child to register
     */
    static void registerItem(KeyboardInterface *child);

    /**
     * unregister an item from notifications
     * @param child child to unregister
     */
    static void unregisterItem(KeyboardInterface *child);

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

private:
    KeyboardGrabber(QObject *parent = 0);
    ~KeyboardGrabber();

    virtual bool eventFilter(QObject *object, QEvent *event)override;
    static KeyboardGrabber* self;
    QList<KeyboardInterface*> childs;

};

#endif // KEYBOARDGRABBER_H
