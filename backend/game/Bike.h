#ifndef BIKE_H
#define BIKE_H

#include <vector>
#include <stdlib.h>
#include <string>

#include "Position.h"
#include "Player.h"

#include <iostream>

using std::vector;
using std::min;
using std::max;
using std::string;

namespace tron{
    enum Direction {up, right, down, left};
}

using namespace tron;

class Player;

/**
 * @brief The Bike class
 */
class Bike
{
public:
    /**
     * constructs a new bike
     * @param x x-coordinate
     * @param y y-coordinate
     * @param startDirection tron::[up|right|down|left]
     * @param color html-color, e.g. "#ff0000"
     * @param baseSpeed base speed of the bike
     * @param maxSpeed maximum speed of the bike
     * @param speedUp speedup factor
     */
    Bike(float x, float y, Direction startDirection, string color = "#ff0000", float baseSpeed = 150, float maxSpeed = 250, float speedUp = 4.f);

    /**
     * get path of the bike
     * @return returns a vector of positions, building the bikes path
     */
    vector<Position> getPath();

    /**
     * change direction of the bike
     * @param newDirection up, down, left or right
     */
    void changeDirection(Direction newDirection);

    /**
     * update the bike its position
     * @param millisecond current time in milliseconds
     * @param allWalls needed for calculating the acceleration
     */
    void update(long millisecond, vector<vector<Position> > allWalls);

    /**
     * @param newColor new color
     */
    void changeColor(string newColor);

    /**
     * @return color as string
     */
    string getColor();

    /**
     * @return position of the bike
     */
    Position getPosition();

    /**
     * @return whether the bike is in gameover-state or not
     */
    bool isGameOver();

    /**
     * set the associated player
     * @param player player which is related to this bike
     */
    void setPlayer(Player* player);

    /**
     * @return player associated with this bike or NULL if cpu
     */
    Player *getPlayer();

    /**
     * enable and disable inputs
     * @param enabled true = inputs enabled, false = disabled
     */
    void enableInput(bool enabled = true);

private:

    Position position;      // should be self explaining
    Position lastPosition;  //
    Direction direction;    // cur direction the bike is pointing to
    float baseSpeed;        // pixel per second
    float maxSpeed;         // pixel per second
    float speed;            // pixel per second
    float acceleration;     // pixel per square-second
    float speedUpFactor;    // factor
    vector<Position> path;  // path of positions
    string color;           // color-code as string
    bool gameOver;          // true if bike got crashed
    bool inputEnabled;
    Player *player;

    bool isBetween(float point_1, float point_2, float needle);
    bool isBetween_I(int point_1, int point_2, int needle);
    bool checkCrash(vector< vector<Position> > allWalls);
    void updatePosition(float timePased);
    void calcAcceleration(vector<vector<Position> > allWalls);
};

#endif // BIKE_H
