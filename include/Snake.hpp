#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Point.hpp"
#include "Direction.hpp"

class Snake {
    std::vector<Point> body;
    Direction faceDirection = Direction::NORTH;

public:
    Snake();
    Snake(std::vector<Point> body);
    Snake(std::initializer_list<Point> points);

    void moveTo(const Point &point);
    void moveTo(int x, int y);
    void eat(int x, int y);
    size_t getSize();
    void reset();
    Point getBody(unsigned int index);
    void turnFace(Direction direction);
    Direction getFaceDirection();
    Point getHead();
    bool isPointOnBody(Point &point);
    Point getLookedPoint();

    // debug
    void printFaceDirection();
};

#endif
