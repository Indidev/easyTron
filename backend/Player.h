#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QTimer>

#include <string>
#include <ctime>

#include "Bike.h"
#include "backend/KeyboardGrabber.h"

using std::string;

class Bike;

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(string name, Bike* bike, int keys[4], QObject *parent = 0);
    string getName();

signals:

public slots:
    void changeDirection(QKeyEvent *event);
    void doChange();

private:

    int keys[4];
    Bike* bike;
    string name;
    long lastKeyinMs;
    int nextDirection;
    QTimer timer;

};

#endif // PLAYER_H
