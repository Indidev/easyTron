#ifndef LOBBY_H
#define LOBBY_H

#include <QObject>

#include "frontend/MainFrame.h"
#include "frontend/game/LobbyWidget.h"
#include "backend/util/InputEvent.h"
#include "backend/util/InputGrabber.h"

class Lobby : public QObject
{
    Q_OBJECT
public:
    explicit Lobby();

signals:

public slots:
    void onInput(InputEvent);

protected:
    LobbyWidget *lobbyFrontend;

};

#endif // LOBBY_H
