#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <QWidget>
#include <QKeyEvent>

#include "backend/KeyboardGrabber.h"

namespace Ui {
class GameOverScreen;
}

class GameOverScreen : public QWidget
{
    Q_OBJECT

public:
    explicit GameOverScreen(QString winner, QWidget *parent = 0);
    ~GameOverScreen();

private:
    Ui::GameOverScreen *ui;

protected slots:
    void c_exit();
    void c_rematch();
    void onKey(QKeyEvent *event);

signals:
    void exit();
    void rematch();
};

#endif // GAMEOVERSCREEN_H
