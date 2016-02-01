#include "CountdownWidget.h"

CountdownWidget::CountdownWidget(int countFrom, QString text, int duration)
{
    this->counter = countFrom;
    this->endText = text;
    this->duration = duration;

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
    static int t = 0;
    curLabel->setText(text);
    curLabel->setVisible(true);
    curLabel->setStyleSheet("color:rgba(255, 255, 255, " + QString::number(255 * t / duration) + "); font-size: 100pt; font-weight: bold;");

    curLabel->setGeometry(0, 0, this->width(), this->height());
    t += Ticker::timePassed();
    if (t >= duration) {
        counter--;
        t = 0;
    }
}
