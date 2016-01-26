#ifndef TICKER_H
#define TICKER_H

#include <QTimer>
#include <QTime>
#include <QList>
#include <QMutex>
#include <stdlib.h>

using std::max;

#include "Refreshable.h"

/**
 * @brief The Ticker class
 */
class Ticker : public QTimer
{
    Q_OBJECT

public:
    /**
     * sets the interval of the ticker
     * @param msec interval in msec
     */
    static void setInterval(int msec);

signals:

public slots:
    /**
     * register an item
     * @param item item to register
     * @param enabled whether the item is enabled or not
     */
    static void registerItem(Refreshable* item, bool enabled = false);

    /**
     * unregisters an item
     * @param item item to unregister
     */
    static void removeItem(Refreshable* item);

    /**
     * enable or disable a specific item
     * @param item item whichs state should be changed
     * @param enabled true = enable
     */
    static void enable(Refreshable* item, bool enabled = true);

    /**
     * enables all items
     * @param msec optional interval in milliseconds of the timer
     */
    static void startAll(int msec = -1);

    /**
     * disables all items
     */
    static void stopAll();

    /**
     * start the timer
     * @param msec optional interval in milliseconds
     */
    static void start(int msec = -1);

    /**
     * stop the timer
     */
    static void stop();

    /**
     * @return returns the current interval
     */
    static int interval();

    /**
     * @return number of ticks/frames per second
     */
    static int fps();

    /**
     * @return time passed since the last tick (1000 / fps)
     */
    static int timePassed();

    /**
     * @return instance of the ticker
     */
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
