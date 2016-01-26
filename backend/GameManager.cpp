#include "GameManager.h"

static const float FPS = 60;

GameManager::GameManager(QObject *parent) :
    QObject(parent)
{
    updater = NULL;
    showMainMenu();
}

void GameManager::clickedPlay()
{
    QSize mapSize(1000, 1000);
    CountdownWidget *t = new CountdownWidget(3, "");
    MainFrame::showOverlay(t, true);

    Bike *bike = new Bike(100, 300, tron::right, "#ffff00");
    int keys[] = {Qt::Key_Up, Qt::Key_Down, Qt::Key_Left, Qt::Key_Right};
    new Player("Player 1", bike, keys);

    int keys2[] = {Qt::Key_W, Qt::Key_S, Qt::Key_A, Qt::Key_D};
    bikes.append(bike);
    bike = new Bike(900, 700, tron::left, "#00ffff");
    new Player("Player 2", bike, keys2);
    bikes.append(bike);
    updater = new BikeUpdater(bikes, QRect(QPoint(0, 0), mapSize));
    Ticker::registerItem(updater);
    playArea = new PlayArea(bikes, mapSize, this);

    MainFrame::showWidget(playArea);

    //disable keys
    playArea->enableKeys(false);
    bikes.enableInput(false);

    Ticker::start(1000 / FPS);

    connect(t, SIGNAL(finished()), this, SLOT(play()));

    connect(updater, SIGNAL(gameOver(Bike*)), this, SLOT(endGame(Bike*)));
    t->start();
}

void GameManager::play()
{
    MainFrame::removeOverlay();
    Ticker::start(updater);
    playArea->enableKeys();
    bikes.enableInput();
}

void GameManager::clickedExit()
{

    Ticker::removeItem(updater);
    QApplication::exit(0);
}

void GameManager::clickedOptions()
{

}

void GameManager::pause()
{
    Ticker::stop();

    playArea->enableKeys(false);
    bikes.enableInput(false);
    MainFrame::showOverlay(new IngameMenu(this));
}

void GameManager::resume()
{
    MainFrame::removeOverlay();
    playArea->enableKeys();
    bikes.enableInput();
    Ticker::start();
}

void GameManager::endGame(Bike *winner)
{
    GameOverScreen *gos = new GameOverScreen(winner && winner->getPlayer()?
                                                 QString::fromStdString(winner->getPlayer()->getName()):
                                                 "");
    MainFrame::showOverlay(gos);

    //connect cleanup
    connect(gos, SIGNAL(exit()), this, SLOT(cleanGame()));
    connect(gos, SIGNAL(rematch()), this, SLOT(cleanGame()));
    //connect action
    connect(gos, SIGNAL(exit()), this, SLOT(showMainMenu()));
    connect(gos, SIGNAL(rematch()), this, SLOT(clickedPlay()));
}

void GameManager::cleanGame()
{
    bikes.clear();
    MainFrame::removeOverlay();
}

void GameManager::showMainMenu() {
    MainMenu *menu = new MainMenu(this);

    MainFrame::showWidget(menu);
}
