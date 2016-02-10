#ifndef MAINMENU_H
#define MAINMENU_H

#include "EasyTronDef.h"
#include <QWidget>

#include "backend/GameManager.h"

namespace Ui {
class MainMenu;
}

/**
 * @brief The MainMenu class
 * //TODO implement key actions
 */
class MainMenu : public QWidget
{
    Q_OBJECT

public:
    /**
     * constructs the main menu
     */
    MainMenu();
    ~MainMenu();

private:
    Ui::MainMenu *ui;

protected slots:
    void c_exit() {emit(exit());}
    void c_play() {emit(play());}
    void c_options() {emit(options());}

signals:
    void play();
    void options();
    void exit();
};

#endif // MAINMENU_H
