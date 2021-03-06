#ifndef EASYTRON_H
#define EASYTRON_H

#include <QString>

//Backend
class BikeController;
class LocalBikeController;
class Bike;
class BikeList;
class Lobby;
class Position;
class Input;
class Output;
class Ticker;
class Refreshable;
class InputEvent;
class InputGrabber;
class InputInterface;
class InputMapping;
class JoystickListener;
class Options;
class GameManager;

//Frontend
class CountdownWidget;
class GameOverScreen;
class LobbyWidget;
class PlayArea;
class PlayingField;
class IngameMenu;
class MainMenu;
class LayeredWidget;
class MainFrame;

//Enums
namespace tron{
    enum Direction {up, right, down, left};
}

//Structs
struct RowData {
    BikeController *controller;
    QString color;
    QString status;
};

#endif // EASYTRON_H
