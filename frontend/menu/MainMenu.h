#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

#include "backend/GameManager.h"

namespace Ui {
class MainMenu;
}

class GameManager;

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    MainMenu(GameManager *manager, QWidget *parent = 0);
    ~MainMenu();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
