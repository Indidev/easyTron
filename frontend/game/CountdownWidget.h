#ifndef COUNTDOWNWIDGET_H
#define COUNTDOWNWIDGET_H

#include "EasyTronDef.h"
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <backend/time/Ticker.h>

/**
 * @brief The CountdownWidget class
 */
class CountdownWidget : public QWidget, public Refreshable
{
    Q_OBJECT
public:
    /**
     * constructor
     * @param countFrom number to count from (0 to show just the text)
     * @param text text to display if finished
     * @param duration duration each number and the text will be shown (in ms)
     */
    explicit CountdownWidget(int countFrom = 3, QString text = "GO", int duration = 500);
    ~CountdownWidget();

    /**
     * start animation
     */
    void start();

    /**
     * implemented for Refreshable interface
     */
    void tick();
protected:
    QLabel *curLabel;
    int counter;
    QString endText;
    int duration;

    void show(QString text);
signals:
    void finished();

public slots:

};

#endif // COUNTDOWNWIDGET_H
