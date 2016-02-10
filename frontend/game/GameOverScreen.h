#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include "EasyTronDef.h"
#include <QWidget>
#include <QKeyEvent>

#include "backend/util/InputGrabber.h"

namespace Ui {
class GameOverScreen;
}

/**
 * @brief The GameOverScreen class
 */
class GameOverScreen : public QWidget
{
    Q_OBJECT

public:
    /**
     * constructs a game over widget
     * @param winner name of the winner
     */
    explicit GameOverScreen(QString winner);
    ~GameOverScreen();

private:
    Ui::GameOverScreen *ui;

protected slots:
    /**
     * clicked exit or esc
     */
    void c_exit();

    /**
     * clicked rematch or return
     */
    void c_rematch();

    /**
     * KeyboardGrabber interface
     */
    void onKey(InputEvent event);

signals:
    /**
     * signal for "player wants to exit"
     */
    void exit();

    /**
     * signal for "player wants a rematch"
     */
    void rematch();
};

#endif // GAMEOVERSCREEN_H
