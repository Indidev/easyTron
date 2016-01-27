#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>

#include "game/PlayArea.h"
#include "LayeredWidget.h"
#include "backend/game/Bike.h"
#include "backend/game/Player.h"
#include "backend/util/KeyboardGrabber.h"

namespace Ui {
class MainFrame;
}

/**
 * @brief The MainFrame class
 * the main window
 */
class MainFrame : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * creates the new window
     */
    explicit MainFrame();
    ~MainFrame();

    /**
     * show a widget at the screen (deletes the old one!)
     * @param widget widget to display
     */
    static void showWidget(QWidget *widget);

    /**
     * shows an overlay over the current widget
     * @param widget widget to show on the top-layer
     * @param mouseTransparent true if you want to click through that widget
     */
    static void showOverlay(QWidget *widget, bool mouseTransparent = false);

    /**
     * exactly what it sounds like
     */
    static void removeOverlay();

protected:
    Ui::MainFrame *ui;
    static MainFrame *self;

    LayeredWidget *layeredWidget;
    QWidget *curWidget;
    QWidget *curOverlay;
    QWidget *lowerLayer;
    QWidget *upperLayer;

    void setWidget(QWidget *layer, QWidget **displayWidget, QWidget *widget, bool mouseTransparent = false);
    void init();

protected slots:
    void onKey(QKeyEvent *event);
};

#endif // MAINFRAME_H
