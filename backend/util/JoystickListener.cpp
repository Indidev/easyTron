#include "JoystickListener.h"

int JoystickListener::X_AXIS_MASK = 0b1000000000000;
int JoystickListener::Y_AXIS_MASK = 0b0100000000000;
int JoystickListener::Z_AXIS_MASK = 0b0010000000000;
int JoystickListener::R_AXIS_MASK = 0b0001000000000;
int JoystickListener::U_AXIS_MASK = 0b0000100000000;
int JoystickListener::V_AXIS_MASK = 0b0000010000000;
int JoystickListener::JOYNUM_MASK = 0b0000001110000;
int JoystickListener::KEY_MASK =    0b0000000001111;

int JoystickListener::JOYNUM_OFFSET = 4;

int JoystickListener::MASK[] = {JoystickListener::X_AXIS_MASK, JoystickListener::Y_AXIS_MASK, JoystickListener::Z_AXIS_MASK,
                                       JoystickListener::R_AXIS_MASK, JoystickListener::U_AXIS_MASK, JoystickListener::V_AXIS_MASK,
                                       JoystickListener::KEY_MASK};
QString JoystickListener::NAMES[] = {"X AXIS", "Y AXIS", "Z AXIS", "R AXIS", "U AXIS", "V AXIS", "Key"};
sf::Joystick::Axis JoystickListener::AXIS[] = {sf::Joystick::X, sf::Joystick::Y, sf::Joystick::Z, sf::Joystick::R, sf::Joystick::U, sf::Joystick::V};


JoystickListener::JoystickListener()
{
    connect(this, SIGNAL(timeout()), this, SLOT(checkButtons()));
    this->start(50);
}

void JoystickListener::checkButtons()
{
    //update joysticks
    sf::Joystick::update();

    //itterate through all joysticks
    for (int stick = 0; stick < sf::Joystick::Count; stick++) {

        int stickValue = stick << JOYNUM_OFFSET;
        if (sf::Joystick::isConnected(stick)) {

            //itterate over axis
            for (unsigned int axis = 0; axis < 2; axis++) {
                if (sf::Joystick::hasAxis(stick, AXIS[axis])) {

                    float v = sf::Joystick::getAxisPosition(stick, AXIS[axis]);

                    //check negativ and positiv axis
                    for (int i = -1; i < 2; i+=2) {
                        QString name = "Pad " + QString::number(stick) + (i<0?": -":": ") + NAMES[axis];
                        InputEvent event(i * (MASK[axis] | stickValue), name);
                        if (v / (50 * i) > 0) {
                            if (!pressedBtns.contains(event)) {
                                pressedBtns.append(event);
                                emit btnPress(event);
                            }
                        } else if (pressedBtns.contains(event)) {
                            pressedBtns.removeAll(event);
                            emit btnRelease(event);
                        }
                    }
                }
            }

            //itterate over all buttons
            for (unsigned int btn = 0; btn < sf::Joystick::getButtonCount(stick); btn++) {
                QString name = "Pad " + QString::number(stick) + ": Button " + QString::number(btn);
                InputEvent event(stickValue | btn, name);
                if (sf::Joystick::isButtonPressed(stick, btn)) {
                    if (!pressedBtns.contains(event)) {
                        pressedBtns.append(event);
                        emit btnPress(event);
                    }
                } else if (pressedBtns.contains(event)) {
                        pressedBtns.removeAll(event);
                        emit btnRelease(event);
                }
            }
        }
    }
}
