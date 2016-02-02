#ifndef LOBBYWIDGET_H
#define LOBBYWIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QList>

#include <QPainter>

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
    void addRow(int num); //TODO redo this with a whole row instead of a number
    void removeRow(int num);
    void changeColor(int num);
signals:
    void c_exit();
    void c_go();

protected:
    Ui::LobbyWidget *ui;

    struct RowData {
        int playerNum;      //TODO should redo this with bike controler instead
        QString playerName; //is contained in the bike of the controler
        QString color;      //let this be, can set the bikes color afterwards
        QString controls;   //bike controler...
        QString status;     //let this
    };

    QList<RowData*> rows;
    QStringList takenColors;
    QStringList colors;

    void updateTable();
    void nextColor(RowData *data);
    RowData *findData(int num);
};

#endif // LOBBYWIDGET_H
