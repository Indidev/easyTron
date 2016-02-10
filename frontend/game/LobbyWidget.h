#ifndef LOBBYWIDGET_H
#define LOBBYWIDGET_H

#include "EasyTronDef.h"
#include <QWidget>
#include <QTableWidgetItem>
#include <QList>

#include <QPainter>
#include <QRgb>
#include <backend/game/controller/BikeController.h>

namespace Ui {
class LobbyWidget;
}

//TODO comment whole class
class LobbyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LobbyWidget();
    ~LobbyWidget();
    void addRow(BikeController *controller); //TODO redo this with a controller
    void removeRow(BikeController *controller);
    void changeColor(BikeController *controller);
signals:
    void c_exit();
    void c_go();

protected:
    Ui::LobbyWidget *ui;

    struct RowData {
        BikeController *controller;
        QString color;
        QString status;
    };

    QList<RowData*> rows;
    QStringList takenColors;
    QStringList colors;

    void updateTable();
    void nextColor(RowData *data);
    RowData *findData(BikeController *controller);
};

#endif // LOBBYWIDGET_H
