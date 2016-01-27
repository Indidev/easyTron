#ifndef TICKER_H
#define TICKER_H

#include <QTimer>
#include <QTime>
#include <QList>
#include <QMutex>
#include <stdlib.h>

using std::max;

class Refreshable;

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

    explicit Ticker();

    static void checkSelf();

protected slots:
    void onTimer();
};

/**
 * @brief The Refreshable interface
 */
class Refreshable {
public:
    /**
     * constructor of Refreshables
     * @param active wheteher it should be active or not, default is false
     */
    Refreshable(bool active = false) {
        Ticker::registerItem(this, active);
    }

    ~Refreshable() { Ticker::removeItem(this); }

    /**
     * enable or disable ticks for this class
     * @param enabled default = true
     */
    void enableTicks(bool enabled = true) {
        Ticker::enable(this, enabled);
    }

    /**
     * tick will be called from a timer to refresh the child class
     */
    virtual void tick() = 0;
};

#endif // TICKER_H
