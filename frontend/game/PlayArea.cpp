#include "PlayArea.h"

PlayArea::PlayArea(QList<Bike *> bikes, QSize mapSize, GameManager *manager, QList<Bike *> trackedBikes, QWidget *parent) :
    QWidget(parent)
{
    fpsLabel = NULL;
    fpsEnabled = false;
    namesEnabled = false;
    this->setLayout(new QGridLayout);
    this->layout()->setMargin(0);
    this->layout()->setSpacing(0);

    LayeredWidget *layeredW = new LayeredWidget;
    content = layeredW->addWidget(0);
    statusWidget = layeredW->addWidget(100);
    statusWidget->setLayout(new QGridLayout);
    statusWidget->layout()->setMargin(0);
    statusWidget->layout()->setSpacing(0);

    content->setLayout(new QGridLayout);
    content->layout()->setMargin(0);

    //create upper and lower layouts for game content (splitscreen included)
    QWidget *upperW = new QWidget;
    upperRow = new QHBoxLayout;
    upperRow->setMargin(0);

    upperW->setLayout(upperRow);

    this->layout()->addWidget(layeredW);

    content->layout()->addWidget(upperW);

    this->mapSize = mapSize;
    this->bikes = bikes;
    this->manager = manager;

    keysEnabled = true;

    display = QImage(mapSize + QSize(2 * BORDER_WIDTH,2 * BORDER_WIDTH), QImage::Format_ARGB32);
    display.fill(QColor("#00ff00"));

    //layouting
    doLayout(trackedBikes);

    //set timer for window refreshing
    Ticker::registerItem(this, true);

    //connect keyboard grabber
    connect(KeyboardGrabber::instance(), SIGNAL(keyPress(QKeyEvent*)), this, SLOT(keyInput(QKeyEvent*)));
}

PlayArea::~PlayArea()
{
    Ticker::removeItem(this);
}

void PlayArea::doLayout(QList<Bike *> trackedBikes)
{
    for (Bike* bike : trackedBikes) {
        fields.append(new PlayingField(mapSize, bike));
    }

    // add full map, if no player should be tracked or number of players is odd and larger then two
    if (fields.size() == 0 || (fields.size() > 2 && fields.size() % 2)) {
        fields.append(new PlayingField(mapSize));
    }
    if (fields.size() <= 2) {
        for (PlayingField* field : fields)
            upperRow->addWidget(field);
    } else {
        QWidget *lowerW = new QWidget;
        lowerRow = new QHBoxLayout;
        lowerRow->setMargin(0);
        lowerW->setLayout(lowerRow);
        content->layout()->addWidget(lowerW);

        for (int i = 0; i < fields.size(); i++) {
            if (i < fields.size() / 2) {
                upperRow->addWidget(fields[i]);
            } else {
                lowerRow->addWidget(fields[i]);
            }
        }
    }
}

void PlayArea::enableKeys(bool enable)
{
    keysEnabled = enable;
}

void PlayArea::showFPS(bool enable)
{
    static int c = 0;

    //create fps label if not present
    if (!fpsLabel) {
        fpsLabel = new QLabel;

        //create fps label
        QWidget *fpsWidget = new QWidget;
        fpsWidget->setLayout(new QGridLayout);
        fpsWidget->layout()->setSpacing(10);
        fpsWidget->layout()->setMargin(10);

        //add and align fps label
        fpsWidget->layout()->addWidget(fpsLabel);
        fpsLabel->setAlignment(Qt::AlignRight);

        //add fps to status layout
        statusWidget->layout()->addWidget(fpsWidget);

        //make font settings
        fpsLabel->setFont(QFont("Helvetica [Cronyx]", 20, 3));
        fpsLabel->setStyleSheet("color: rgba(255, 168, 0, 255)");
    }

    if (enable) {
        if (!(c++ % 10))
            fpsLabel->setText(QString::number(Ticker::fps()));
        c %= 10;
    } else {
        fpsLabel->setText("");
    }
}

void PlayArea::tick()
{
    render();
}

void PlayArea::render()
{
    QImage field(mapSize, QImage::Format_ARGB32);
    QPainter painter;
    painter.begin(&field);

    drawBackground(&painter);
    drawBikes(&painter);

    painter.end();


    painter.begin(&display);
    painter.drawImage(BORDER_WIDTH, BORDER_WIDTH, field);
    painter.end();

    for (PlayingField* field : fields) {
        field->applyRender(display);
    }
    showFPS(fpsEnabled);
}

void PlayArea::keyInput(QKeyEvent *event)
{
    if (keysEnabled) {
        switch (event->key()) {
        case Qt::Key_Escape:
            manager->pause();
            break;
        case Qt::Key_F11:
            toggleFPS();
            break;
        case Qt::Key_F10:
            toggleNames();
            break;
        }
    }
}

void PlayArea::toggleFPS()
{
    fpsEnabled = !fpsEnabled;
}

void PlayArea::toggleNames()
{
    namesEnabled = !namesEnabled;
}

void PlayArea::drawBackground(QPainter *painter)
{

    //fill background
    painter->fillRect(0, 0, mapSize.width(), mapSize.height(), QColor("#032c3f"));

    painter->setPen(QColor(255, 255, 255, 100));

    //draw vertical lines
    for (int x = -1; x < mapSize.width(); x += 30) {
        painter->drawLine(x, 0, x, mapSize.height());
    }

    //draw horizontal lines
    for (int y = -1; y < mapSize.height(); y += 30) {
        painter->drawLine(0, y, mapSize.width(), y);
    }
}

void PlayArea::drawBikes(QPainter *painter)
{
    // do for each bike
    for (Bike *bike: bikes) {

        //paint bike
        QColor bikeColor(QString::fromStdString(bike->getColor()));

        painter->setBrush(QBrush(bikeColor));
        vector<Position> path = bike->getPath();
        painter->drawEllipse(path.back().x - 3, path.back().y - 3, 6, 6);

        //paint walls
        painter->setPen(QPen(bikeColor, 2));
        drawWalls(path, painter);

        painter->setPen(QPen(bikeColor, 1));

        //paint name
        if (namesEnabled) {
            QString name = bike->getPlayer()?
                        QString::fromStdString(bike->getPlayer()->getName()):
                        "CPU";

            painter->drawText(path.back().x, path.back().y, name);
        }
    }
}

void PlayArea::drawWalls(vector<Position> wall, QPainter *painter)
{

    for (unsigned int i = 1; i < wall.size(); i++) {
        QPoint p1(wall[i - 1].x, wall[i - 1].y);
        QPoint p2(wall[i].x, wall[i].y);

        painter->drawLine(p1, p2);
    }
}
