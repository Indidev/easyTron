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

/**
 * a widget building the frontend to the lobby itself which contains all data.
 */
class LobbyWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * creates a new lobby widget
     */
    explicit LobbyWidget();
    ~LobbyWidget();

    /**
     * updates the widgets table
     * @param rows data to display
     */
    void updateTable(QList<RowData *> &rows);

    /**
     * activate and deactivate the go button
     * @param active whether it should be active or not
     */
    void enableGoButton(bool enabled);
signals:
    /**
     * indicates that exit was pressed
     */
    void c_exit();
    /**
     * indicates that the go button was pressed
     */
    void c_go();

protected:
    Ui::LobbyWidget *ui;

};

#endif // LOBBYWIDGET_H
