#include "IngameMenu.h"
#include "ui_IngameMenu.h"

IngameMenu::IngameMenu(GameManager *manager, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IngameMenu)
{
    ui->setupUi(this);
    this->manager = manager;

    connect(ui->exitButton, SIGNAL(clicked()), manager, SLOT(clickedExit()));
    connect(ui->resumeButton, SIGNAL(clicked()), manager, SLOT(resume()));
    connect(ui->OptionButton, SIGNAL(clicked()), manager, SLOT(clickedOptions()));
    connect(KeyboardGrabber::instance(), SIGNAL(keyPress(QKeyEvent*)), this, SLOT(onKey(QKeyEvent*)));
}

IngameMenu::~IngameMenu()
{
    delete ui;
}

void IngameMenu::onKey(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
        manager->resume();
}
