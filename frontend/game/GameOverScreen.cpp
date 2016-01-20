#include "GameOverScreen.h"
#include "ui_GameOverScreen.h"

GameOverScreen::GameOverScreen(QString winner, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOverScreen)
{
    ui->setupUi(this);
    ui->winner_lbl->setText(winner);

    connect(ui->exit_btn, SIGNAL(clicked()), this, SLOT(c_exit()));
    connect(ui->rematch_btn, SIGNAL(clicked()), this, SLOT(c_rematch()));
    connect(KeyboardGrabber::instance(), SIGNAL(keyPress(QKeyEvent*)), this, SLOT(onKey(QKeyEvent*)));
}

GameOverScreen::~GameOverScreen()
{
    delete ui;
}

void GameOverScreen::c_exit()
{
    emit exit();
}

void GameOverScreen::c_rematch()
{
    emit rematch();
}

void GameOverScreen::onKey(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
        c_exit();
    else if (event->key() == Qt::Key_Return)
        c_rematch();
}
