#ifndef KEYBOARDGRABBER_H
#define KEYBOARDGRABBER_H

#include <QObject>
#include <QApplication>
#include <QKeyEvent>
#include "InputInterface.h"
#include "JoystickListener.h"
#include "InputEvent.h"
#include "backend/game/controller/BikeController.h"

class BikeController;

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

    /**
     * input from a bike controller
     * @param direction direction which is pressed
     * @param ctrl pointer to the controller
     */
    static void pushedDirection(tron::Direction direction, BikeController *ctrl);

signals:
    /**
     * input press event
     * @param event input-event
     */
    void inputPress(InputEvent event);

    /**
     * input release event
     * @param event input-event
     */
    void inputRelease(InputEvent event);

    /**
     * emit the bike controllers signal
     * @param direction direction which is pressed
     * @param ctrl pointer to the controller
     */
    void ctrlDirection(tron::Direction direction, BikeController *ctrl);

protected:
    InputGrabber();
    ~InputGrabber();

    virtual bool eventFilter(QObject *object, QEvent *event)override;
    static InputGrabber* self;
    QList<InputInterface*> childs;

#ifndef NO_SFML
    JoystickListener *joyListener;
#endif
protected slots:
    void press(InputEvent event);
    void release(InputEvent event);
    void emitCtrlDir(tron::Direction dir, BikeController *ctrl) {emit ctrlDirection(dir, ctrl);}
};

#endif // KEYBOARDGRABBER_H
