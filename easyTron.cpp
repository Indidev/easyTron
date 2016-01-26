#include <QApplication>

#include "frontend/MainFrame.h"
#include "backend/GameManager.h"
#include "backend/Options.h"

//TODO remove before release
#include "backend/Options.h"
#include "iostream"

using std::cout;
using std::endl;

void test();

int main(int argc, char *argv[])
{
    //TODO remove before release
    test();
    QApplication a(argc, argv);
    MainFrame w;
    w.show();

    Options::registerForKeys();

    new GameManager;

    return a.exec();
}

//TODO remove before release
void test() {
    cout << "Version: " << Options::getMainVersion() << "." << Options::getMinnorVersion() << endl;
}
