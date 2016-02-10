#ifndef LOBBY_H
#define LOBBY_H

#include "EasyTronDef.h"
#include <QObject>

#include "frontend/MainFrame.h"
#include "frontend/game/LobbyWidget.h"
#include "backend/util/InputGrabber.h"
#include "backend/game/controller/BikeController.h"
#include "backend/util/InputEvent.h"

//todo comment
class Lobby : public QObject
{
    Q_OBJECT
public:
    explicit Lobby();

signals:
    void c_exit();
    void c_go();

public slots:
    void onCtrlInput(tron::Direction direction, BikeController *controller);
    void onInput(InputEvent event);

protected:
    LobbyWidget *lobbyFrontend;
};

#endif // LOBBY_H