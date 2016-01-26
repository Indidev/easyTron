#ifndef BIKELIST_H
#define BIKELIST_H

#include <QList>

#include "Bike.h"

/**
 * @brief The BikeList class
 * like QStringList, just for Bikes
 */
class BikeList : public QList<Bike *> {
public:
    /**
     * enable or disable input of all bikes in this list
     * @param enabled true = enabled, false = disabled
     */
    void enableInput(bool enabled = true) {
        for (Bike* bike : *this) {
            bike->enableInput(enabled);
        }
    }
};

#endif // BIKELIST_H
