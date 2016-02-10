#ifndef PLAYAREA_H
#define PLAYAREA_H

#include "EasyTronDef.h"
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

#include "backend/game/Bike.h"
#include "backend/GameManager.h"
#include "backend/time/Ticker.h"
#include "backend/util/InputGrabber.h"
#include "backend/util/Options.h"

#include "PlayingField.h"
#include "frontend/LayeredWidget.h"

static const int BORDER_WIDTH = 2;

/**
 * @brief The PlayArea class
 * the play area consists of a game layer, including one to multiple game fields, as well as status layers.
 */
class PlayArea : public QWidget, Refreshable
{
    Q_OBJECT

public:
    /**
     * constructs a play area widget
     * @param bikes list of all bikes which are in the game
     * @param mapSize size of the map
     * @param manager game manager
     * @param trackedBikes bikes to keep track with or an empty list, to track none of the bikes
     */
    explicit PlayArea(QList<Bike*> bikes, QSize mapSize, GameManager* manager, QList<Bike*> trackedBikes = QList<Bike*>());
    ~PlayArea();

    /**
     * enable or disable key inputs
     * @param enable true = enabled
     */
    void enableKeys(bool enable = true);

    /**
     * Refreshable interface
     */
    void tick();

protected:

    QSize mapSize;
    QImage display;
    QImage bg;
    QList<Bike*> bikes;
    QList<PlayingField*> fields;
    GameManager *manager;
    QLayout *upperRow;
    QLayout *lowerRow;
    QWidget *statusWidget;
    QLabel *fpsLabel;
    QWidget *content;

    bool keysEnabled;

    void drawBackground(QPainter *painter);
    void drawBikes(QPainter *painter);
    void drawWalls(vector<Position> wall, QPainter *painter);
    void doLayout(QList<Bike*> trackedBikes);
    void showFPS();

protected slots:
    void render();
    void keyInput(InputEvent event);
};

#endif // PLAYAREA_H
