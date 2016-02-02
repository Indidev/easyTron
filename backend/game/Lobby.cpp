#include "Lobby.h"

Lobby::Lobby()
{
    lobbyFrontend = new LobbyWidget;
    MainFrame::showWidget(lobbyFrontend);
    connect(InputGrabber::instance(), SIGNAL(inputPress(InputEvent)), this, SLOT(onInput(InputEvent)));
    connect(lobbyFrontend, SIGNAL(c_exit()), this, SIGNAL(c_exit()));
    connect(lobbyFrontend, SIGNAL(c_go()), this, SIGNAL(c_go()));
}

void Lobby::onInput(InputEvent)
{

}
