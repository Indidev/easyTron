#include "Ticker.h"

#include <QTimer>

Ticker *Ticker::self = NULL;
QMutex Ticker::mutex(QMutex::Recursive);
QList<Refreshable*> Ticker::disabledItems;
QList<Refreshable*> Ticker::enabledItems;
int Ticker::curFPS = -1;
int Ticker::elapsedTime = 0;
bool Ticker::elapsedActive = false;
QTime Ticker::time;

Ticker::Ticker()
{
    self = this;

    connect(this, SIGNAL(timeout()), this, SLOT(onTimer()));
}

void Ticker::setInterval(int msec)
{
    checkSelf();

    self->QTimer::setInterval(msec);
}

void Ticker::registerItem(Refreshable *item, bool enabled)
{
    checkSelf();

    mutex.lock();

    enabledItems.removeAll(item);
    disabledItems.removeAll(item);

    if (enabled) {
        enabledItems.append(item);
    } else {
        disabledItems.append(item);
    }
    mutex.unlock();
}

void Ticker::removeItem(Refreshable *item)
{
    checkSelf();
    mutex.lock();
    enabledItems.removeAll(item);
    disabledItems.removeAll(item);

    if (enabledItems.empty())
        self->QTimer::stop();

    mutex.unlock();
}

void Ticker::enable(Refreshable *item, bool enabled)
{
    if (enabled)
        start();
    mutex.lock();
    registerItem(item, enabled);
    mutex.unlock();
}

void Ticker::start(int msec)
{
    checkSelf();
    if (msec >= 0)
        setInterval(msec);

    self->QTimer::start();
}

void Ticker::stop()
{
    checkSelf();
    elapsedActive = false;
    elapsedTime = 0;

    self->QTimer::stop();
}

void Ticker::startAll(int msec)
{
    start(msec);

    mutex.lock();
    enabledItems.append(disabledItems);
    disabledItems.clear();
    mutex.unlock();
}

void Ticker::stopAll()
{
    stop();

    mutex.lock();
    disabledItems.append(enabledItems);
    enabledItems.clear();
    mutex.unlock();
}

const Ticker *Ticker::instance()
{
    checkSelf();

    return self;
}

int Ticker::interval()
{
    checkSelf();

    return self->QTimer::interval();
}

int Ticker::fps()
{
    return curFPS >= 0? curFPS: 0;
}

int Ticker::timePassed()
{
    return elapsedActive? elapsedTime: 0;
}

void Ticker::checkSelf() {
    mutex.lock();
    if (!self)
        self = new Ticker;
    mutex.unlock();
}

void Ticker::onTimer()
{
    mutex.lock();

    enabledItems.removeAll(NULL);
    curFPS = 1000 / max(time.elapsed(), interval());
    elapsedTime = elapsedActive? time.elapsed(): 0;
    time.start();
    for (Refreshable* item: enabledItems) {
        item->tick();
    }
    elapsedActive = true;
    mutex.unlock();
}
