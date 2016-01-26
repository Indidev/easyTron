#ifndef BIKEUPDATER_H
#define BIKEUPDATER_H

#include <QObject>
#include <QList>
#include <QRect>

#include "Bike.h"
#include "Position.h"
#include "backend/time/Refreshable.h"
#include "backend/time/Ticker.h"
#include "backend/game/BikeList.h"

#include <iostream>

/**
 * @brief The BikeUpdater class
 */
class BikeUpdater : public QObject, public Refreshable
{
    Q_OBJECT
public:
    /**
     * constructor
     * @param bikes self explaining
     * @param frame the border of the playing-field (for collision detection with the walls)
     */
    explicit BikeUpdater(BikeList bikes, QRect frame);

protected:
    BikeList bikes;
    vector<Position> border;
    void tick();
signals:
    void gameOver(Bike* winner);
};

#endif // BIKEUPDATER_H
