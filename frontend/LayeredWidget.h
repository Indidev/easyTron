#ifndef LAYEREDWIDGET_H
#define LAYEREDWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QList>
#include <QPair>

class LayeredWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LayeredWidget(QWidget *parent = 0);

    QWidget *addWidget(int z_index);
    void removeWidget(QWidget *widget);
signals:

public slots:

protected:
    QList<QPair<QWidget*, int> > layers;
    QWidget *contentWidget;

    void resizeEvent(QResizeEvent *event);
};

#endif // LAYEREDWIDGET_H
