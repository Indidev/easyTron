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

    void updateTable(QList<RowData *> &rows);
signals:
    void c_exit();
    void c_go();

protected:
    Ui::LobbyWidget *ui;

};

#endif // LOBBYWIDGET_H
