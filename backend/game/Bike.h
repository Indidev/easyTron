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
    enum Direction {up, down, left, right};
}

using namespace tron;

class Player;

class Bike
{
public:
    Bike(float x, float y, Direction startDirection, string color = "#ff0000", float baseSpeed = 150, float maxSpeed = 250, float speedUp = 4.f);

    vector<Position> getPath();
    void changeDirection(Direction newDirection);
    void update(long millisecond, vector<vector<Position> > allWalls);
    void changeColor(string newColor);
    Position getPosition();
    bool isGameOver();
    void setPlayer(Player* player);
    Player *getPlayer();
    void enableInput(bool enabled = true);

    string getColor();

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
