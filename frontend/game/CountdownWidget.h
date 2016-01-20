#ifndef COUNTDOWNWIDGET_H
#define COUNTDOWNWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <backend/Refreshable.h>
#include <backend/Ticker.h>

class CountdownWidget : public QWidget, public Refreshable
{
    Q_OBJECT
public:
    explicit CountdownWidget(int countFrom, QString text, QWidget *parent = 0);
    void start();

    void tick();
    ~CountdownWidget();
protected:
    enum State{three, two, one, go, fin};
    QLabel *curLabel;
    State curState;

    void show(QString text);
signals:
    void finished();

public slots:

};

#endif // COUNTDOWNWIDGET_H
