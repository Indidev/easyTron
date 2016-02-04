#include "Lobby.h"

Lobby::Lobby()
{
    lobbyFrontend = new LobbyWidget;
    MainFrame::showWidget(lobbyFrontend);
    connect(InputGrabber::instance(), SIGNAL(inputPress(InputEvent)), this, SLOT(onInput(InputEvent)));
    connect(lobbyFrontend, SIGNAL(c_exit()), this, SIGNAL(c_exit()));
    connect(lobbyFrontend, SIGNAL(c_go()), this, SIGNAL(c_go()));
}

void Lobby::onInput(InputEvent event)
{
    if (InputMapping::isPlayerAction(event)) {

        int playerNum = InputMapping::getPlayerAction(event).first;

        switch (InputMapping::getPlayerAction(event).second) {
            case tron::up:
                lobbyFrontend->addRow(playerNum);
                break;
            case tron::down:
                lobbyFrontend->removeRow(playerNum);
                break;
            default:
                lobbyFrontend->changeColor(playerNum);
        }
    } else {
        switch (event.key()) {
        case Qt::Key_Escape : emit c_exit();
            break;
        case Qt::Key_Return : emit c_go();
        }
    }
}
