#include "MainMenu.h"
#include "ui_MainMenu.h"

MainMenu::MainMenu(GameManager *manager, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    connect(ui->playBtn, SIGNAL(clicked()), manager, SLOT(clickedPlay()));
    connect(ui->optionsBtn, SIGNAL(clicked()), manager, SLOT(clickedOptions()));
    connect(ui->exitBtn, SIGNAL(clicked()), manager, SLOT(clickedExit()));
}

MainMenu::~MainMenu()
{
    delete ui;
}
