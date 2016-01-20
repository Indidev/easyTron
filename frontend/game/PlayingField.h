#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H

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

#include "backend/Bike.h"

class PlayingField : public QWidget
{
    Q_OBJECT

public:
    explicit PlayingField(QSize mapSize = QSize(800, 600), Bike *trackedBike = NULL, QWidget *parent = 0);
    ~PlayingField();
    void applyRender(QImage &display);

private:
    QSize mapSize;
    Bike *trackedBike;
    QLabel *field;
};

#endif // PLAYINGFIELD_H
