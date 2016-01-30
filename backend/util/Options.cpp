#include "Options.h"

Options* Options::self = NULL;

Options::Options()
{
    loadOptions();
}

Options::~Options()
{
    saveOptions();
}

Options *Options::instance()
{
    if (!self)
        self = new Options;

    return self;
}

void Options::loadOptions()
{
    showNames = false;
    showFPS = false;

    QHash<QString, QString> version = Input::loadMap("versionInfo");
    mainVersion = version.value("main").toInt();
    minnorVersion = version.value("minnor").toInt();
}

void Options::saveOptions()
{

}

void Options::toggleFPS()
{
    showFPS = !showFPS;
}

void Options::toggleNames()
{
    showNames = !showNames;
}

int Options::getMainVersion()
{
    return instance()->mainVersion;
}

int Options::getMinnorVersion()
{
    return instance()->minnorVersion;
}

void Options::registerForKeys()
{
    InputGrabber::registerItem(instance());
}

void Options::unregisterForKeys()
{
    InputGrabber::unregisterItem(instance());
}

bool Options::namesVisible()
{
    return instance()->showNames;
}

bool Options::fpsVisible()
{
    return instance()->showFPS;
}

void Options::onPress(QKeyEvent *ev)
{
    switch (ev->key()) {
    case Qt::Key_F11:
        toggleFPS();
        break;
    case Qt::Key_F10:
        toggleNames();
        break;
    }
}

void Options::onRelease(QKeyEvent *)
{
}
