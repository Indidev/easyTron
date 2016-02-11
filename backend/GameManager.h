#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "EasyTronDef.h"
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
#include "backend/game/Lobby.h"
#include "backend/util/InputMapping.h"

/**
 * @brief The GameManager class
 * this class manages the game itself
 * //TODO delegate tasks and restructure the whole class
 */
class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager();
    ~GameManager();

signals:

public slots:
    void clickedPlay();
    void clickedExit();
    void clickedOptions();
    void startGame();
    void pause();
    void resume();
    void endGame(Bike* winner);
    void cleanGame();
    void showMainMenu();
    void removeLobby();

protected:

    BikeList bikes;
    PlayArea *playArea;
    Lobby *lobby;
    QList<RowData*> data;

protected slots:
    void play();
};

#endif // GAMEMANAGER_H
