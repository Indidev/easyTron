#include "PlayingField.h"

/**
 * @param mapSize size of the playing field
 * @param trackedBike bike to track (NULL = global view)
 */
PlayingField::PlayingField(QSize mapSize, Bike* trackedBike, QWidget *parent) :
    QWidget(parent)
{
    field = new QLabel;
    field->setAlignment(Qt::AlignCenter);

    this->setLayout(new QGridLayout);
    this->layout()->setMargin(0);
    this->layout()->setSpacing(0);
    this->layout()->addWidget(field);

    this->mapSize = mapSize;
    this->trackedBike = trackedBike;
}

PlayingField::~PlayingField()
{
}

/**
 * display the Image
 * @param display image to display
 */
void PlayingField::applyRender(QImage &display)
{
    float fw = field->width();
    float fh = field->height();
    float dw = display.width();
    float dh = display.height();
    if (dw <= fw && dh <= fh)
        field->setPixmap(QPixmap::fromImage(display));
    else {
        if (!trackedBike) { //full view (resize display)
            QImage resized;
            if ((dw / dh) < (fw / fh))
                resized = display.scaledToHeight(fh);
            else
                resized = display.scaledToWidth(fw);
            field->setPixmap(QPixmap::fromImage(resized));
        } else { //track a bike (crop)
            int left = min(max(0, (int) trackedBike->getPosition().x - (int) fw / 2), max(0, (int) (dw - fw)));
            int top = min(max(0, (int) trackedBike->getPosition().y - (int) fh / 2), max(0, (int) (dh - fh)));

            QImage cropped = display.copy(left, top, min(display.width(), (int) fw), min(display.height(), (int) fh));
            field->setPixmap(QPixmap::fromImage(cropped));
        }
    }
}
