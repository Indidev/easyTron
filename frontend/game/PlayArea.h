#ifndef PLAYAREA_H
#define PLAYAREA_H

#include <QWidget>
#include <QSize>
#include <QImage>
#include <QPainter>
#include <QList>
#include <QPen>
#include <QKeyEvent>
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>

#include <iostream>

#include "backend/Bike.h"
#include "backend/BikeUpdater.h"
#include "backend/GameManager.h"
#include "backend/Refreshable.h"
#include "backend/Ticker.h"
#include "backend/KeyboardGrabber.h"

#include "PlayingField.h"
#include "frontend/LayeredWidget.h"

static const int BORDER_WIDTH = 2;

class GameManager;

class PlayArea : public QWidget, Refreshable
{
    Q_OBJECT

public:
    explicit PlayArea(QList<Bike*> bikes, QSize mapSize, GameManager* manager, QList<Bike*> trackedBikes = QList<Bike*>(), QWidget *parent = 0);
    void enableKeys(bool enable = true);
    void showFPS(bool enable = true);
    void tick();
    ~PlayArea();

protected:

    QSize mapSize;
    QImage display;
    QList<Bike*> bikes;
    QList<PlayingField*> fields;
    GameManager *manager;
    QLayout *upperRow;
    QLayout *lowerRow;
    QWidget *statusWidget;
    QLabel *fpsLabel;
    QWidget *content;

    bool namesEnabled;
    bool fpsEnabled;
    bool keysEnabled;

    void drawBackground(QPainter *painter);
    void drawBikes(QPainter *painter);
    void drawWalls(vector<Position> wall, QPainter *painter);
    void doLayout(QList<Bike*> trackedBikes);

protected slots:
    void render();
    void keyInput(QKeyEvent *event);
    void toggleFPS();
    void toggleNames();
};

#endif // PLAYAREA_H
