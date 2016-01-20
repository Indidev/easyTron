#include "Bike.h"

Bike::Bike(float x, float y, Direction startDirection, std::string color, float baseSpeed, float maxSpeed, float speedUp)
{
    player = NULL;
    gameOver = false;
    position = Position(x, y);
    lastPosition = position;
    path.push_back(position);

    this->color = color;
    this->direction = startDirection;
    this->baseSpeed = baseSpeed;
    this->maxSpeed = maxSpeed;
    this->speedUpFactor = speedUp;
    this->inputEnabled = true;

    acceleration = 0;
    speed = baseSpeed;
}

/**
 * get path of the bike
 * @return returns a vector of positions, building the bikes path
 */
vector<Position> Bike::getPath()
{
    //copy of curent path + curent postion
    vector<Position> p = path;
    p.push_back(position);
    return p;
}

/**
 * change direction of the bike
 * @param newDirection up, down, left or right
 */
void Bike::changeDirection(Direction newDirection)
{
    if (!inputEnabled)
        return;

    if (direction != newDirection && (direction + newDirection) % 4 != 1) { //ignore same direction as well as inverse direction
        direction = newDirection;
        speed -= baseSpeed / 20;
        path.push_back(position);
    }
}

/**
 * update the bike its position
 * @param millisecond current time in milliseconds
 * @param allWalls needed for calculating the acceleration
 */
void Bike::update(long millisecond, vector<vector<Position> > allWalls)
{
    checkCrash(allWalls);
    calcAcceleration(allWalls);
    updatePosition(millisecond);
}

/**
 * @param newColor new color
 */
void Bike::changeColor(std::string newColor)
{
    color = newColor;
}

/**
 * @return position of the bike
 */
Position Bike::getPosition()
{
    return position;
}

/**
 * @return color as string
 */
std::string Bike::getColor()
{
    return color;
}

void Bike::calcAcceleration(vector< vector<Position> > allWalls)
{
    acceleration = speed < baseSpeed? 10: -5;

    // iterate through all cars
    for (vector<Position> bike : allWalls) {

        // iterate through all corners
        for (unsigned int i = 1; i < bike.size(); i++) {
            Position lastCorner = bike[i - 1];
            Position curCorner = bike[i];

            float distance = -1;

            // calculate distance to wall
            if (direction < left) {
                if (lastCorner.x == curCorner.x && isBetween(lastCorner.y, curCorner.y, position.y)) {
                    distance = abs(position.x - curCorner.x);
                }
            } else {
                if (lastCorner.y == lastCorner.y&& isBetween(lastCorner.x, curCorner.x, position.x)) {
                    distance = abs(position.y - curCorner.y);
                }
            }

            // calculate acceleration
            if (isBetween(1, 10, distance)) {
                acceleration += speedUpFactor * 10.f - speedUpFactor *distance;
            }
        }
    }
}

bool Bike::isGameOver()
{
    return gameOver;
}

void Bike::setPlayer(Player *player)
{
    this->player = player;
}

Player *Bike::getPlayer()
{
    return player;
}

void Bike::enableInput(bool enabled)
{
    inputEnabled = enabled;
}

void Bike::updatePosition(float timePased)
{
    if (gameOver)
        return;

    lastPosition = position;

    float oldSpeed = speed;
    speed += acceleration * timePased / 1000;
    speed = min(speed, maxSpeed);
    speed = max(speed, baseSpeed * 2 / 3);

    float distance = (speed + oldSpeed) * timePased / 2000; // avg speed = (speed + oldSpeed) / 2

    switch (direction) {
        case up:
            position.y -= distance;
            break;
        case down:
            position.y += distance;
            break;
        case left:
            position.x -= distance;
            break;
        default:    //right
            position.x += distance;
    }
}

bool Bike::isBetween(float point_1, float point_2, float needle)
{
    return needle >= min(point_1, point_2) && needle <= max(point_1, point_2);
}

bool Bike::isBetween_I(int point_1, int point_2, int needle)
{
    return needle >= min(point_1, point_2) && needle <= max(point_1, point_2);
}

bool Bike::checkCrash(vector< vector<Position> > allWalls)
{
    for (vector<Position> bike : allWalls) {
        if (gameOver)
            break;

        for (unsigned int i = 1; i < bike.size() && !gameOver; i++) {
            Position p1 = bike[i];
            Position p2 = bike[i - 1];
            if ((p1 != position &&  p1 != lastPosition) || path[0] != bike[0]) {

                //if (direction < left) {
                    if ((isBetween_I(p1.x, p2.x, position.x) && isBetween_I(lastPosition.y, position.y, p1.y))
                       || (isBetween_I(p1.y, p2.y, position.y) && isBetween_I(lastPosition.x, position.x, p1.x)) )
                        gameOver = true;
                //}

            }
        }
    }
    return gameOver;
}
