#include "MainMenu.h"
#include "ui_MainMenu.h"

MainMenu::MainMenu() :
    QWidget(),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    connect(ui->playBtn, SIGNAL(clicked()), this, SLOT(c_play()));
    connect(ui->optionsBtn, SIGNAL(clicked()), this, SLOT(c_options()));
    connect(ui->exitBtn, SIGNAL(clicked()), this, SLOT(c_exit()));
}

MainMenu::~MainMenu()
{
    delete ui;
}
