#include "MainFrame.h"
#include "ui_MainFrame.h"

MainFrame *MainFrame::self = NULL;

MainFrame::MainFrame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainFrame)
{
    init();
}

MainFrame::~MainFrame()
{
    delete ui;
}

void MainFrame::init() {
    self = this;
    curWidget = NULL;
    curOverlay = NULL;

    ui->setupUi(this);

    layeredWidget = new LayeredWidget();
    ui->centralWidget->layout()->addWidget(layeredWidget);

    lowerLayer = layeredWidget->addWidget(0);
    upperLayer = layeredWidget->addWidget(10);

    lowerLayer->setLayout(new QGridLayout);
    upperLayer->setLayout(new QGridLayout);

    lowerLayer->layout()->setMargin(0);
    lowerLayer->layout()->setSpacing(0);
    upperLayer->layout()->setMargin(0);
    upperLayer->layout()->setSpacing(0);

    connect(KeyboardGrabber::instance(), SIGNAL(keyPress(QKeyEvent*)), this, SLOT(onKey(QKeyEvent*)));

    upperLayer->setAttribute(Qt::WA_TransparentForMouseEvents);
}

void MainFrame::onKey(QKeyEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_Q) {
        exit(0);
    } else if ((event->modifiers() & Qt::AltModifier) && event->key() == Qt::Key_Return) {
        //toggle fullscreen
        if (isFullScreen())
            showNormal();
        else
            showFullScreen();
    }
}

void MainFrame::showWidget(QWidget *widget)
{
    self->setWidget(self->lowerLayer, &(self->curWidget), widget);
}

void MainFrame::showOverlay(QWidget *widget, bool mouseTransparent)
{
    self->setWidget(self->upperLayer, &(self->curOverlay), widget, mouseTransparent);
}

void MainFrame::removeOverlay()
{
    self->setWidget(self->upperLayer, &(self->curOverlay), NULL, true);
}

void MainFrame::setWidget(QWidget *layer, QWidget **displayWidget, QWidget *widget, bool mouseTransparent) {
    if (*displayWidget) {
        (*displayWidget)->setVisible(false);
        layer->layout()->removeWidget(*displayWidget);
        (*displayWidget)->deleteLater();
    }
    *displayWidget = widget;
    if (widget)
        layer->layout()->addWidget(widget);

    layer->setAttribute(Qt::WA_TransparentForMouseEvents, mouseTransparent);
}
