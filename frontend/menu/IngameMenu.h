#ifndef INGAMEMENU_H
#define INGAMEMENU_H

#include <QWidget>

#include "backend/GameManager.h"

namespace Ui {
class IngameMenu;
}

class GameManager;

class IngameMenu : public QWidget
{
    Q_OBJECT

public:
    explicit IngameMenu(GameManager *manager, QWidget *parent = 0);
    ~IngameMenu();

protected:
    Ui::IngameMenu *ui;
    GameManager *manager;

protected slots:
    void onKey(QKeyEvent *event);
};

#endif // INGAMEMENU_H
