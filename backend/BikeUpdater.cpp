#include "BikeUpdater.h"

BikeUpdater::BikeUpdater(QList<Bike *> bikes, QRect frame)
{
    this->bikes = bikes;

    int p[4];
    frame.getRect(p, p+1, p+2, p+3);
    p[2] += p[0];
    p[2] += p[1];

    for (int i = 0; i < 5; i++)
        border.push_back(Position(p[((i + 1) % 4 / 2) * 2], p[((i % 4 / 2) * 2 + 1)]));
}

void BikeUpdater::tick()
{

    vector<vector<Position> > walls;
    walls.push_back(border);
    for (Bike *bike : bikes) {
        walls.push_back(bike->getPath());
    }

    for (Bike *bike : bikes) {
        bike->update(Ticker::timePassed(), walls);
    }

    int activeBikes = bikes.length();
    Bike* winner = NULL;
    for (Bike* bike : bikes) {
        if (bike->isGameOver()) {
            activeBikes--;
        } else {
            winner = bike;
        }
    }

    if (activeBikes < 2) {
        Ticker::removeItem(this);
        emit gameOver(winner); //could also be NULL
    }
}
