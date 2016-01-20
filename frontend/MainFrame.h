#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>

#include "game/PlayArea.h"
#include "LayeredWidget.h"
#include "backend/Bike.h"
#include "backend/BikeUpdater.h"
#include "backend/Player.h"
#include "backend/KeyboardGrabber.h"

namespace Ui {
class MainFrame;
}

class MainFrame : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainFrame(QWidget *parent = 0);
    ~MainFrame();
    static void showWidget(QWidget *widget);
    static void showOverlay(QWidget *widget, bool mouseTransparent = false);
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
