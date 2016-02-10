#include <QApplication>

#include "frontend/MainFrame.h"
#include "backend/GameManager.h"
#include "backend/util/Options.h"

//TODO remove before release
#include "iostream"

using std::cout;
using std::endl;

void test();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //TODO remove before release
    test();
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
