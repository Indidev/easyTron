#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include <QApplication>

#include "backend/game/Bike.h"
#include "backend/game/BikeList.h"
#include "backend/time/Ticker.h"

#include "frontend/MainFrame.h"
#include "frontend/menu/MainMenu.h"
#include "frontend/menu/IngameMenu.h"
#include "frontend/game/PlayArea.h"
#include "frontend/game/CountdownWidget.h"
#include "frontend/game/GameOverScreen.h"
#include "backend/game/controller/LocalBikeController.h"

// todo remove, cause not necessary for the game
#include "backend/util/InputEvent.h"
#include "backend/util/JoystickListener.h"

class PlayArea;

/**
 * @brief The GameManager class
 * this class manages the game itself
 * //TODO delegate tasks
 */
class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager();

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
    PlayArea *playArea;

protected slots:
    void play();
};

#endif // GAMEMANAGER_H
