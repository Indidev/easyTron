#ifndef BIKE_H
#define BIKE_H

#include <vector>
#include <stdlib.h>
#include <string>

#include "Position.h"

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
    Bike(float x, float y, Direction startDirection, string name, string color = "#ff0000", float baseSpeed = 150, float maxSpeed = 250, float speedUp = 4.f);

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
    void update(long millisecond, vector<vector<Position> > &allWalls);

    /**
     * @param newColor new color
     */
    void changeColor(string newColor) {color = newColor;}

    /**
     * @return color as string
     */
    string getColor() {return color;}

    /**
     * @return position of the bike
     */
    Position getPosition() {return position;}

    /**
     * @return whether the bike is in gameover-state or not
     */
    bool isGameOver() {return gameOver;}

    /**
     * enable and disable inputs
     * @param enabled true = inputs enabled, false = disabled
     */
    void enableInput(bool enabled = true) {inputEnabled = enabled;}

    /**
     * @return players name
     */
    string getName() {return name;}

    /**
     * method to get walls of all players, including the border wall, usefull for impementing cpu-opponents
     * @return
     */
    vector< vector<Position> > getAllWalls() {return allWalls;}

    /**
     * @return current direction the bike is facing
     */
    Direction getCurDirection() {return direction;}

private:

    Position position;      // should be self explaining
    Position lastPosition;  //
    Direction direction;    // cur direction the bike is pointing to
    float baseSpeed;        // pixel per second
    float maxSpeed;         // pixel per second
    float speed;            // pixel per second
    float acceleration;     // pixel per square-second
    float speedUpFactor;    // factor
    bool gameOver;          // true if bike got crashed
    bool inputEnabled;      // true if input is enabled
    vector<Position> path;  // path of positions
    string color;           // color-code as string
    string name;            // name of the player
    vector< vector<Position> > allWalls;

    bool isBetween(float point_1, float point_2, float needle);
    bool isBetween_I(int point_1, int point_2, int needle);
    bool checkCrash();
    void updatePosition(float timePased);
    void calcAcceleration();
};

#endif // BIKE_H
