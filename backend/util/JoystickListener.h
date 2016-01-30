#ifndef JOYSTICKLISTENER_H
#define JOYSTICKLISTENER_H

#include <QTimer>
#include <SFML/Window/Joystick.hpp>
#include <QList>
#include <QPair>

#include "InputEvent.h"

//TODO remove this after testing
#include <iostream>
using namespace std;

class JoystickListener : public QTimer
{
    Q_OBJECT
public:
    explicit JoystickListener();

    static int X_AXIS_MASK;
    static int Y_AXIS_MASK;
    static int Z_AXIS_MASK;
    static int R_AXIS_MASK;
    static int U_AXIS_MASK;
    static int V_AXIS_MASK;
    static int JOYNUM_MASK;
    static int KEY_MASK;

    static int JOYNUM_OFFSET;

    static int MASK[];
    static QString NAMES[];

    static int getJoystickNum(int keycode) {return (keycode & JOYNUM_MASK) >> JOYNUM_OFFSET;}

signals:

    void btnPress(InputEvent event);
    void btnRelease(InputEvent event);

protected:
    static sf::Joystick::Axis AXIS[];
    QList<InputEvent > pressedBtns;

protected slots:
    void checkButtons();

};

#endif // JOYSTICKLISTENER_H
