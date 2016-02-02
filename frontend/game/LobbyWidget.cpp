#include "LobbyWidget.h"
#include "ui_LobbyWidget.h"

LobbyWidget::LobbyWidget() :
    ui(new Ui::LobbyWidget)
{
    ui->setupUi(this);
    connect(ui->exitBtn, SIGNAL(clicked()), this, SIGNAL(c_exit()));
    connect(ui->goBtn, SIGNAL(clicked()), this, SIGNAL(c_go()));
}

LobbyWidget::~LobbyWidget()
{
    delete ui;
}
