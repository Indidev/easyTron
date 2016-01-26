#ifndef OPTIONS_H
#define OPTIONS_H

#include <QHash>

#include "backend/io/Input.h"
#include "backend/io/Output.h"
#include "backend/util/KeyboardInterface.h"
#include "backend/util/KeyboardGrabber.h"

class Options : public KeyboardInterface
{
public:
    static int getMainVersion();
    static int getMinnorVersion();
    static void registerForKeys();
    static void unregisterForKeys();
    static bool namesVisible();
    static bool fpsVisible();

    void onPress(QKeyEvent *ev);
    void onRelease(QKeyEvent *ev);

protected:
    Options();
    ~Options();

    static Options *instance();
    void loadOptions();
    void saveOptions();
    void toggleFPS();
    void toggleNames();
    int mainVersion;
    int minnorVersion;
    static Options *self;
    bool showFPS;
    bool showNames;
};

#endif // OPTIONS_H
