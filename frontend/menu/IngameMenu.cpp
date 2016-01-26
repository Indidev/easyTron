#include "IngameMenu.h"
#include "ui_IngameMenu.h"

IngameMenu::IngameMenu() :
    QWidget(),
    ui(new Ui::IngameMenu)
{
    ui->setupUi(this);

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(c_exit()));
    connect(ui->resumeButton, SIGNAL(clicked()), this, SLOT(c_resume()));
    connect(ui->OptionButton, SIGNAL(clicked()), this, SLOT(c_options()));
    connect(KeyboardGrabber::instance(), SIGNAL(keyPress(QKeyEvent*)), this, SLOT(onKey(QKeyEvent*)));
}

IngameMenu::~IngameMenu()
{
    delete ui;
}

void IngameMenu::onKey(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
        emit(resume());
}
