#include "GameManager.h"

static const float FPS = 60;

GameManager::GameManager()
{
    showMainMenu();
}

void GameManager::clickedPlay()
{
    new Lobby;
//    QSize mapSize(1000, 1000);
//    CountdownWidget *t = new CountdownWidget;
//    MainFrame::showOverlay(t, true);

//    Bike *bike = new Bike(300, 300, tron::right, "Player 1", "#ffff00");
//    int keys[] = {Qt::Key_Up, Qt::Key_Right, Qt::Key_Down, Qt::Key_Left};
//    new LocalBikeController(bike, keys);

//    InputEvent iE[] = {InputEvent(-JoystickListener::Y_AXIS_MASK), InputEvent(JoystickListener::X_AXIS_MASK),
//                       InputEvent(JoystickListener::Y_AXIS_MASK), InputEvent(-JoystickListener::X_AXIS_MASK)};

//    new LocalBikeController(bike, iE);

//    int keys2[] = {Qt::Key_W, Qt::Key_D, Qt::Key_S, Qt::Key_A};
//    bikes.append(bike);
//    bike = new Bike(900, 700, tron::left, "CPU 1", "#00ffff");
//    new LocalBikeController(bike, keys2);

//    bikes.append(bike);
//    bikes.setBorder(QRect(QPoint(0, 0), mapSize));

//    playArea = new PlayArea(bikes, mapSize, this);

//    MainFrame::showWidget(playArea);

//    //disable keys
//    playArea->enableKeys(false);
//    bikes.enableInput(false);

//    Ticker::start(1000 / FPS);

//    connect(t, SIGNAL(finished()), this, SLOT(play()));

//    connect(&bikes, SIGNAL(gameOver(Bike*)), this, SLOT(endGame(Bike*)));
//    t->start();
}

void GameManager::play()
{
    MainFrame::removeOverlay();
    playArea->enableKeys();
    bikes.enableInput();
    bikes.enableTicks();
}

void GameManager::clickedExit()
{
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
    IngameMenu *im = new IngameMenu;
    MainFrame::showOverlay(im);
    connect(im, SIGNAL(resume()), this, SLOT(resume()));
    connect(im, SIGNAL(options()), this, SLOT(clickedOptions()));

    connect(im, SIGNAL(exit()), this, SLOT(cleanGame()));
    connect(im, SIGNAL(exit()), this, SLOT(showMainMenu()));
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
    GameOverScreen *gos = new GameOverScreen(winner?QString::fromStdString(winner->getName()):"Draw");
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
    bikes.enableTicks(false);
    bikes.clear();
    MainFrame::removeOverlay();
}

void GameManager::showMainMenu() {
    MainMenu *menu = new MainMenu();
    MainFrame::showWidget(menu);

    connect(menu, SIGNAL(play()), this, SLOT(clickedPlay()));
    connect(menu, SIGNAL(options()), this, SLOT(clickedOptions()));
    connect(menu, SIGNAL(exit()), this, SLOT(clickedExit()));
}
