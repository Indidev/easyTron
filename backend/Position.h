#ifndef POSITION_H
#define POSITION_H

#include <stdlib.h>
class Position
{
public:
    Position() {x = 0; y = 0;}   /// empty constructor
    Position(float x, float y) {this->x = x; this->y = y;}
    float x;    // x-position
    float y;    // y-position

    bool operator==(const Position &other)
    {
        return (int)this->x == (int) other.x && (int) this->y == (int) other.y;
    }
    bool operator!=(const Position &other)
    {
        return !(*this == other);
    }
};

#endif // POSITION_H
