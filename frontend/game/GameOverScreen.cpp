#include "GameOverScreen.h"
#include "ui_GameOverScreen.h"

GameOverScreen::GameOverScreen(QString winner) :
    ui(new Ui::GameOverScreen)
{
    ui->setupUi(this);
    ui->winner_lbl->setText(winner);

    connect(ui->exit_btn, SIGNAL(clicked()), this, SLOT(c_exit()));
    connect(ui->rematch_btn, SIGNAL(clicked()), this, SLOT(c_rematch()));
    connect(InputGrabber::instance(), SIGNAL(inputPress(InputEvent)), this, SLOT(onKey(InputEvent)));
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

void GameOverScreen::onKey(InputEvent event)
{
    if (event.type() != InputEvent::qtInput)
        return;

    if (event.key() == Qt::Key_Escape)
        c_exit();
    else if (event.key() == Qt::Key_Return)
        c_rematch();
}
