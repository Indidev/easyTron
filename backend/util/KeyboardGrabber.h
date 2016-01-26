#ifndef KEYBOARDGRABBER_H
#define KEYBOARDGRABBER_H

#include <QObject>
#include <QApplication>
#include <QKeyEvent>
#include "KeyboardInterface.h"

class KeyboardGrabber : public QObject
{
    Q_OBJECT
public:
    ~KeyboardGrabber();

    virtual bool eventFilter(QObject *object, QEvent *event)override;
    static KeyboardGrabber* instance();
    static void registerItem(KeyboardInterface *child);
    static void unregisterItem(KeyboardInterface *child);

signals:
    void keyPress(QKeyEvent *event);
    void keyRelease(QKeyEvent *event);

public slots:

private:
    KeyboardGrabber(QObject *parent = 0);
    static KeyboardGrabber* self;
    QList<KeyboardInterface*> childs;

};

#endif // KEYBOARDGRABBER_H
