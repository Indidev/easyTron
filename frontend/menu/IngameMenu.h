#ifndef INGAMEMENU_H
#define INGAMEMENU_H

#include <QWidget>

#include "backend/GameManager.h"
#include "backend/util/InputEvent.h"

namespace Ui {
class IngameMenu;
}

/**
 * @brief The IngameMenu class
 * ingame menu, gets visible if the player pushes esc during a game
 */
class IngameMenu : public QWidget
{
    Q_OBJECT

public:
    /**
     * creates an ingame menu
     */
    explicit IngameMenu();
    ~IngameMenu();

protected:
    Ui::IngameMenu *ui;

protected slots:
    void onKey(InputEvent event);
    void c_exit() {emit(exit());}
    void c_resume() {emit(resume());}
    void c_options() {emit(options());}

signals:
    void resume();
    void options();
    void exit();
};

#endif // INGAMEMENU_H
