#ifndef BIKELIST_H
#define BIKELIST_H

#include <QList>

#include "Bike.h"

class BikeList : public QList<Bike *> {
public:
    void enableInput(bool enabled = true) {
        for (Bike* bike : *this) {
            bike->enableInput(enabled);
        }
    }
};

#endif // BIKELIST_H
