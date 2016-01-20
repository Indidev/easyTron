#ifndef KEYBOARDGRABBER_H
#define KEYBOARDGRABBER_H

#include <QObject>
#include <QApplication>
#include <QKeyEvent>

class KeyboardGrabber : public QObject
{
    Q_OBJECT
public:
    ~KeyboardGrabber();

    virtual bool eventFilter(QObject *object, QEvent *event)override;
    static KeyboardGrabber* instance();

signals:
    void keyPress(QKeyEvent *event);
    void keyRelease(QKeyEvent *event);

public slots:

private:
    KeyboardGrabber(QObject *parent = 0);
    static KeyboardGrabber* self;

};

#endif // KEYBOARDGRABBER_H
