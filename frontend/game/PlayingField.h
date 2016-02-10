#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H

#include "EasyTronDef.h"
#include <QWidget>
#include <QSize>
#include <QImage>
#include <QPainter>
#include <QTimer>
#include <QList>
#include <QPen>
#include <QGridLayout>
#include <QLabel>

#include <iostream>

#include "backend/game/Bike.h"

/**
 * @brief The PlayingField class
 * Displays the rendered picture and is able to track a single bike.
 */
class PlayingField : public QWidget
{
    Q_OBJECT

public:
    /**
     * construct a view of the field
     * @param mapSize size of the map
     * @param trackedBike tracked bike, or NULL if no bike should be tracked
     */
    explicit PlayingField(QSize mapSize, Bike *trackedBike = NULL);

    /**
     * applys the prerendered picture, here is where the bike-tracking (crop) or resize happens
     * @param display prerendered picture
     */
    void applyRender(QImage &display);

private:
    QSize mapSize;
    Bike *trackedBike;
    QLabel *field;
};

#endif // PLAYINGFIELD_H
