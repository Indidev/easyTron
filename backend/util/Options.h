#ifndef OPTIONS_H
#define OPTIONS_H

#include <QHash>

#include "backend/io/Input.h"
#include "backend/io/Output.h"
#include "backend/util/InputInterface.h"
#include "backend/util/InputGrabber.h"
#include "backend/util/InputEvent.h"

/**
 * @brief The Options class
 * contains lots of options
 */
class Options : public InputInterface
{
public:
    /**
     * @return main version number
     */
    static int getMainVersion();

    /**
     * @return minnor version number
     */
    static int getMinnorVersion();

    /**
     * register options for key events
     */
    static void registerForKeys();

    /**
     * unregister options for key events
     */
    static void unregisterForKeys();

    /**
     * @return whether names should be visible or not
     */
    static bool namesVisible();

    /**
     * @return whether fps should be visible or not
     */
    static bool fpsVisible();

    void onPress(InputEvent ev);

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
