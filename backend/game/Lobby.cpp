#include "Lobby.h"

Lobby::Lobby()
{
    lobbyFrontend = new LobbyWidget;
    MainFrame::showWidget(lobbyFrontend);
    connect(InputGrabber::instance(), SIGNAL(inputPress(InputEvent)), this, SLOT(onInput(InputEvent)));
    connect(InputGrabber::instance(), SIGNAL(ctrlDirection(tron::Direction,BikeController*,bool)), this, SLOT(onCtrlInput(tron::Direction,BikeController*)));
    connect(lobbyFrontend, SIGNAL(c_exit()), this, SIGNAL(c_exit()));
    connect(lobbyFrontend, SIGNAL(c_go()), this, SIGNAL(c_go()));

    //todo load colors codes... this is pretty dirty!
    colors.append("#ffff00");
    colors.append("#00ffff");
    colors.append("#ff0000");
    colors.append("#00ff00");
    colors.append("#0000ff");
    colors.append("#8e0007");
    colors.append("#006700");
    colors.append("#510052");
    colors.append("#e00a6f");
    colors.append("#ffb129");
    colors.append("#bb29ff");
    colors.append("#02b150");
    colors.append("#8e4307");
    colors.append("#000000");
    colors.append("#919191");
    colors.append("#ffffff");
}

void Lobby::onCtrlInput(Direction direction, BikeController *controller)
{
    switch (direction) {
        case tron::up:
            addRow(controller);
            break;
        case tron::down:
            removeRow(controller);
            break;
        default:
            changeColor(controller);
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

void Lobby::addRow(BikeController *controller)
{
    if (findData(controller))
        return;

    rows.append(new RowData{controller, "", "no Status"});
    nextColor(rows.last());
    lobbyFrontend->updateTable(rows);
}

void Lobby::removeRow(BikeController *controller)
{
    RowData *dataPtr = findData(controller);
    if (dataPtr) {
        takenColors.removeAll(dataPtr->color);
        rows.removeAll(dataPtr);
        lobbyFrontend->updateTable(rows);
    }
}

void Lobby::changeColor(BikeController *controller)
{
    RowData *dataPtr = findData(controller);
    if (dataPtr) {
        nextColor(dataPtr);
        lobbyFrontend->updateTable(rows);
    }
}

void Lobby::nextColor(RowData *data)
{
    int index = colors.indexOf(QRegExp(data->color));
    takenColors.removeAll(data->color);
    data->color = "";
    int cancelCounter = 0;

    while (data->color.isEmpty() && cancelCounter < 16) {
        index++;
        index %= colors.size();

        if (!takenColors.contains(colors[index])) {
            data->color = colors[index];
            takenColors.append(colors[index]);
        }
        cancelCounter++;
    }
}

RowData *Lobby::findData(BikeController *controller)
{
    for (RowData *row: rows) {
        if (row->controller == controller)
            return row;
    }
    return NULL;
}
