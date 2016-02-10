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

    /**
     * get the Data of the lobby
     * @return data
     */
    QList<RowData*> *getData();

signals:
    /**
     * pressed exit
     */
    void c_exit();

    /**
     * pressed go
     */
    void c_go();

protected:
    LobbyWidget *lobbyFrontend;

    QList<RowData*> rows;
    QStringList takenColors;
    QStringList colors;

    void nextColor(RowData *data);
    RowData *findData(BikeController *controller);

    void addRow(BikeController *controller); //TODO redo this with a controller
    void removeRow(BikeController *controller);
    void changeColor(BikeController *controller);

protected slots:
    void onCtrlInput(tron::Direction direction, BikeController *controller);
    void onInput(InputEvent event);
};

#endif // LOBBY_H
