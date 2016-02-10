#include "GameManager.h"

static const float FPS = 60;
static const float START_POS[] = {.6, .4, .8, .2, .4, .6, .8, .2};

GameManager::GameManager()
{
    lobby = NULL;
    showMainMenu();
}

GameManager::~GameManager()
{
    for (RowData *date : data)
        delete date;
}

void GameManager::clickedPlay()
{
    lobby = new Lobby;


    connect(lobby, SIGNAL(c_exit()), this, SLOT(showMainMenu()));
    connect(lobby, SIGNAL(c_go()), this, SLOT(startGame()));

    connect(lobby, SIGNAL(c_exit()), this, SLOT(removeLobby()));
    connect(lobby, SIGNAL(c_go()), this, SLOT(removeLobby()));
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
    //todo implement options
}

void GameManager::startGame()
{
    if (lobby) {
        for (RowData *date : data)
            delete date;
        data.clear();

        data = lobby->getData();
    }

    QSize mapSize(1000, 1000);
    CountdownWidget *t = new CountdownWidget;
    MainFrame::showOverlay(t, true);

    //todo add support for more than 8 players
    for (int i = 0; i < data.length() && i < 8; i++) {
        float x = START_POS[i] * mapSize.width();
        float y = START_POS[(i + 6) % 8] * mapSize.height();
        Direction dir = Direction((((i % 4) / 2) * 3 + (i % 2) * 2) % 4);
        Bike *bike = new Bike(x, y, dir, data[i]->color.toStdString(), data[i]->controller);
        bikes.append(bike);
    }

    bikes.setBorder(QRect(QPoint(0, 0), mapSize));

    playArea = new PlayArea(bikes, mapSize, this);

    MainFrame::showWidget(playArea);

    //disable keys
    playArea->enableKeys(false);
    bikes.enableInput(false);

    Ticker::start(1000 / FPS);

    connect(t, SIGNAL(finished()), this, SLOT(play()));

    connect(&bikes, SIGNAL(gameOver(Bike*)), this, SLOT(endGame(Bike*)));

    t->start();
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
    connect(gos, SIGNAL(rematch()), this, SLOT(startGame()));
}

void GameManager::cleanGame()
{
    bikes.enableTicks(false);
    bikes.clear();
    MainFrame::removeOverlay();
}

void GameManager::showMainMenu() {

    removeLobby();

    MainMenu *menu = new MainMenu();
    MainFrame::showWidget(menu);

    connect(menu, SIGNAL(play()), this, SLOT(clickedPlay()));
    connect(menu, SIGNAL(options()), this, SLOT(clickedOptions()));
    connect(menu, SIGNAL(exit()), this, SLOT(clickedExit()));
}

void GameManager::removeLobby()
{
    if (lobby)
        delete lobby;

    lobby = NULL;
}
