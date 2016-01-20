#ifndef BIKEUPDATER_H
#define BIKEUPDATER_H

#include <QObject>
#include <QList>
#include <QRect>

#include "Bike.h"
#include "Position.h"
#include "Refreshable.h"
#include "Ticker.h"

#include <iostream>

class BikeUpdater : public QObject, public Refreshable
{
    Q_OBJECT
public:
    explicit BikeUpdater(QList<Bike*> bikes, QRect frame);

protected:
    QList<Bike*> bikes;
    vector<Position> border;
    void tick();
signals:
    void gameOver(Bike* winner);
};

#endif // BIKEUPDATER_H
