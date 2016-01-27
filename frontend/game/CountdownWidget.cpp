#include "CountdownWidget.h"

static const int FACTOR = 8;

CountdownWidget::CountdownWidget(int countFrom, QString text)
{
    this->counter = countFrom;
    this->endText = text;
    Ticker::registerItem(this);
}

CountdownWidget::~CountdownWidget()
{
    Ticker::removeItem(this);
}

void CountdownWidget::start()
{
    this->setLayout(new QGridLayout);
    this->layout()->setSpacing(0);
    this->layout()->setMargin(0);

    QWidget *w = new QWidget;
    this->layout()->addWidget(w);

    curLabel = new QLabel("test", w);
    curLabel->setStyleSheet("color:white; font-size: 30pt; font-weight: bold;");
    curLabel->setVisible(false);
    curLabel->setAlignment(Qt::AlignCenter);

    Ticker::enable(this);
}

void CountdownWidget::tick()
{
    switch(counter) {
    case 0: show(endText);
        break;
    case -1:
        show("");
        Ticker::removeItem(this);
        emit finished();
        break;
    default:
        show(QString::number(counter));
    }
}

void CountdownWidget::show(QString text) {
    static int i = 0;
    curLabel->setText(text);
    curLabel->setVisible(true);
    curLabel->setStyleSheet("color:rgba(255, 255, 255, " + QString::number(i) + "); font-size: 100pt; font-weight: bold;");

    curLabel->setGeometry(0, 0, this->width(), this->height());
    i += FACTOR;
    if (i >= 255) {
        counter--;
        i = 0;
    }
}
