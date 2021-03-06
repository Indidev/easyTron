#include "IngameMenu.h"
#include "ui_IngameMenu.h"

IngameMenu::IngameMenu() :
    ui(new Ui::IngameMenu)
{
    ui->setupUi(this);

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(c_exit()));
    connect(ui->resumeButton, SIGNAL(clicked()), this, SLOT(c_resume()));
    connect(ui->OptionButton, SIGNAL(clicked()), this, SLOT(c_options()));
    connect(InputGrabber::instance(), SIGNAL(inputPress(InputEvent)), this, SLOT(onKey(InputEvent)));
}

IngameMenu::~IngameMenu()
{
    delete ui;
}

void IngameMenu::onKey(InputEvent event)
{
    if (event.type() != InputEvent::qtInput)
        return;

    if (event.key() == Qt::Key_Escape)
        emit(resume());
}
