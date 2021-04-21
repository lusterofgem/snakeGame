#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Direction.hpp"

class Snake {
    std::vector<Point> body;
    Direction faceDirection = Direction::NORTH;
    sf::Color headColor = sf::Color(255,255,255);
    sf::Color leftEyeColor = sf::Color(255,255,0);
    sf::Color rightEyeColor = sf::Color(255,255,0);
    sf::Color tailColor = sf::Color(150,150,150);

public:
    Snake();
    Snake(std::vector<Point> body);
    Snake(std::initializer_list<Point> points);

    void moveTo(const Point point);
    void moveTo(int x, int y);
    void eat(const Point point);
    void eat(int x, int y);
    size_t getSize();
    void reset();
    Point getBody(unsigned int index);
    void turnFace(Direction direction);
    Direction getFaceDirection();
    Point getHead();
    bool isPointOnBody(Point point);
    Point getLookedPoint();
    void setHeadColor(const sf::Color headColor);
    sf::Color getHeadColor();
    void setLeftEyeColor(const sf::Color leftEyeColor);
    sf::Color getLeftEyeColor();
    void setRightEyeColor(const sf::Color rightEyeColor);
    sf::Color getRightEyeColor();
    void setTailColor(const sf::Color tailColor);
    sf::Color getTailColor();
};

#endif
