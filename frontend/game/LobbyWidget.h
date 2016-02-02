#ifndef LOBBYWIDGET_H
#define LOBBYWIDGET_H

#include <QWidget>

namespace Ui {
class LobbyWidget;
}

class LobbyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LobbyWidget();
    ~LobbyWidget();
signals:
    void c_exit();
    void c_go();

private:
    Ui::LobbyWidget *ui;
};

#endif // LOBBYWIDGET_H
