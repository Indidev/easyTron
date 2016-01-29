#ifndef BIKELIST_H
#define BIKELIST_H

#include <QList>
#include <QObject>
#include <QRect>

#include "Bike.h"
#include "backend/time/Ticker.h"

/**
 * @brief The BikeList class
 * like QStringList, just for Bikes
 */
class BikeList :public QObject, public QList<Bike *>, public Refreshable {
    Q_OBJECT
public:
    /**
     * empty constructor
     */
    BikeList() {}

    /**
     * constructs a new bike list
     * @param border border of the game field
     */
    BikeList(QRect border) {
        setBorder(border);
    }

    /**
     * change the border
     * @param border border of the game field
     */
    void setBorder(QRect border) {
        this->border.clear();

        int p[4];
        border.getRect(p, p+1, p+2, p+3);
        p[2] += p[0];
        p[2] += p[1];

        for (int i = 0; i < 5; i++)
            this->border.push_back(Position(p[((i + 1) % 4 / 2) * 2], p[((i % 4 / 2) * 2 + 1)]));
    }

    /**
     * enable or disable input of all bikes in this list
     * @param enabled true = enabled, false = disabled
     */
    void enableInput(bool enabled = true) {
        for (Bike* bike : *this) {
            bike->enableInput(enabled);
        }
    }
protected:
    vector<Position> border;

    void tick() {
        vector<vector<Position> > walls;
        walls.push_back(border);
        for (Bike *bike : *this) {
            walls.push_back(bike->getPath());
        }

        for (Bike *bike : *this) {
            bike->update(Ticker::timePassed(), walls);
        }

        int activeBikes = length();
        Bike* winner = NULL;
        for (Bike* bike : *this) {
            if (bike->isGameOver()) {
                activeBikes--;
            } else {
                winner = bike;
            }
        }

        if (activeBikes < 2) {
            Ticker::enable(this, false);
            emit gameOver(winner); //could also be NULL
        }
    }


signals:
    void gameOver(Bike* winner);
};

#endif // BIKELIST_H
