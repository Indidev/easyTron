#include "frontend/MainFrame.h"
#include "backend/GameManager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainFrame w;
    w.show();

    new GameManager;

    return a.exec();
}
