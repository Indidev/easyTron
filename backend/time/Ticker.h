#ifndef TICKER_H
#define TICKER_H

#include <QTimer>
#include <QTime>
#include <QList>
#include <QMutex>
#include <stdlib.h>

using std::max;

#include "Refreshable.h"

class Ticker : public QTimer
{
    Q_OBJECT

public:
    static void setInterval(int msec);

signals:

public slots:
    static void registerItem(Refreshable* item, bool enabled = false);
    static void removeItem(Refreshable* item);
    static void start(Refreshable* item);
    static void stop(Refreshable* item);
    static void startAll(int msec = -1);
    static void stopAll();
    static void start(int msec = -1);
    static void stop();
    static int interval();
    static int fps();
    static int timePassed();
    static const Ticker *instance();

protected:
    static Ticker *self;
    static QMutex mutex;
    static QList<Refreshable*> enabledItems;
    static QList<Refreshable*> disabledItems;
    static QTime time;
    static bool elapsedActive;
    static int elapsedTime;
    static int curFPS;

    explicit Ticker(QObject *parent = 0);

    static void checkSelf();

protected slots:
    void onTimer();
};

#endif // TICKER_H
