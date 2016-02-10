#include "Bike.h"

Bike::Bike(float x, float y, Direction startDirection, std::string color, BikeController *ctrl, float baseSpeed, float maxSpeed, float speedUp)
{
    gameOver = false;
    position = Position(x, y);
    lastPosition = position;
    path.push_back(position);
    setController(ctrl);

    this->color = color;
    this->direction = startDirection;
    this->baseSpeed = baseSpeed;
    this->maxSpeed = maxSpeed;
    this->speedUpFactor = speedUp;
    this->inputEnabled = true;

    acceleration = 0;
    speed = baseSpeed;

    InputGrabber::registerItem(this);
}

vector<Position> Bike::getPath()
{
    //copy of curent path + curent postion
    vector<Position> p = path;
    p.push_back(position);
    return p;
}

void Bike::changeDirection(Direction newDirection)
{
    if (!inputEnabled)
        return;

    if ((direction % 2) != (newDirection % 2)) { //ignore same direction as well as inverse direction
        direction = newDirection;
        speed -= baseSpeed / 20;
        path.push_back(position);
    }
}

void Bike::update(long millisecond, vector<vector<Position> > &allWalls)
{
    this->allWalls = allWalls;
    checkCrash();
    calcAcceleration();
    updatePosition(millisecond);
}

void Bike::setController(BikeController *ctrl)
{
    this->ctrl = ctrl;
    if (ctrl)
        name = ctrl->getStdName();
}

void Bike::onCtrlDirection(Direction dir, BikeController *ctrl, bool rel)
{
    if (ctrl == this->ctrl) {
        if (!rel) {
            changeDirection(dir);
        } else {
            changeDirection((Direction) ((getCurDirection() + (Direction::left?3:1)) % 4));
        }
    }
}

void Bike::calcAcceleration()
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
            if (direction % 2 ) { //if % 2 == 1 then the bike rolles vertical, otherwise horizontal
                if (lastCorner.y == lastCorner.y&& isBetween(lastCorner.x, curCorner.x, position.x)) {
                    distance = abs(position.y - curCorner.y);
                }
            } else {
                if (lastCorner.x == curCorner.x && isBetween(lastCorner.y, curCorner.y, position.y)) {
                    distance = abs(position.x - curCorner.x);
                }
            }

            // calculate acceleration
            if (isBetween(1, 10, distance)) {
                acceleration += speedUpFactor * 10.f - speedUpFactor *distance;
            }
        }
    }
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
        case tron::up:
            position.y -= distance;
            break;
        case tron::down:
            position.y += distance;
            break;
        case tron::left:
            position.x -= distance;
            break;
        case tron::right:
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

bool Bike::checkCrash()
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
