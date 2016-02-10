#include "Lobby.h"

Lobby::Lobby()
{
    lobbyFrontend = new LobbyWidget;
    MainFrame::showWidget(lobbyFrontend);
    connect(InputGrabber::instance(), SIGNAL(inputPress(InputEvent)), this, SLOT(onInput(InputEvent)));
    connect(InputGrabber::instance(), SIGNAL(ctrlDirection(tron::Direction,BikeController*,bool)), this, SLOT(onCtrlInput(tron::Direction,BikeController*)));
    connect(lobbyFrontend, SIGNAL(c_exit()), this, SIGNAL(c_exit()));
    connect(lobbyFrontend, SIGNAL(c_go()), this, SIGNAL(c_go()));
}

void Lobby::onCtrlInput(Direction direction, BikeController *controller)
{
    switch (direction) {
        case tron::up:
            lobbyFrontend->addRow(controller);
            break;
        case tron::down:
            lobbyFrontend->removeRow(controller);
            break;
        default:
            lobbyFrontend->changeColor(controller);
    }
}

void Lobby::onInput(InputEvent event)
{
    if (event.type() == InputEvent::qtInput) {
        switch (event.key()) {
        case Qt::Key_Escape : emit c_exit();
            break;
        case Qt::Key_Return : emit c_go();
        }
    }
}
