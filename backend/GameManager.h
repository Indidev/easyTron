#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QApplication>

#include "BikeUpdater.h"
#include "Bike.h"
#include "BikeList.h"
#include "Ticker.h"

#include "frontend/MainFrame.h"
#include "frontend/menu/MainMenu.h"
#include "frontend/menu/IngameMenu.h"
#include "frontend/game/PlayArea.h"
#include "frontend/game/CountdownWidget.h"
#include "frontend/game/GameOverScreen.h"

class PlayArea;

class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager(QObject *parent = 0);

signals:

public slots:
    void clickedPlay();
    void clickedExit();
    void clickedOptions();
    void pause();
    void resume();
    void endGame(Bike* winner);
    void cleanGame();
    void showMainMenu();

protected:

    BikeList bikes;
    BikeUpdater *updater;
    PlayArea *playArea;

protected slots:
    void play();
};

#endif // GAMEMANAGER_H
