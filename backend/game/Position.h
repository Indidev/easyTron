#ifndef POSITION_H
#define POSITION_H

#include "EasyTronDef.h"

/**
 * @brief The Position class
 */
class Position
{
public:
    /**
     * empty constructor
     */
    Position() {x = 0; y = 0;}
    /**
     * construct a new position
     * @param x x-position
     * @param y y-position
     */
    Position(float x, float y) {this->x = x; this->y = y;}

    /**
     * overloaded == operator
     * @param other other position to compare with
     * @return true if equal
     */
    bool operator==(const Position &other)
    {
        return (int)this->x == (int) other.x && (int) this->y == (int) other.y;
    }

    /**
     * overloaded != operator
     * @param other other position to compare with
     * @return true if not equal
     */
    bool operator!=(const Position &other)
    {
        return !(*this == other);
    }

    float x;    // x-position
    float y;    // y-position
};

#endif // POSITION_H
