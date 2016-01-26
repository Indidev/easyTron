#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QTimer>

#include <string>
#include <ctime>

#include "Bike.h"
#include "backend/util/KeyboardGrabber.h"

using std::string;

class Bike;

/**
 * @brief The Player class
 * //TODO change this whole class...
 */
class Player : public QObject
{
    Q_OBJECT
public:
    /**
     * constructs a new player
     * @param name name of the player
     * @param bike bike which belongs to the player
     * @param keys Qt-Key-Codes for controlling //TODO change this
     */
    explicit Player(string name, Bike* bike, int keys[4]);

    /**
     * @return name of the player
     */
    string getName();

signals:

public slots:
    /**
     * slot for changing direction of the bike
     * @param event key-event
     */
    void changeDirection(QKeyEvent *event);

private:

    int keys[4];
    Bike* bike;
    string name;
    long lastKeyinMs;
    int nextDirection;

};

#endif // PLAYER_H
