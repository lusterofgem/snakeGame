#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Direction.hpp"

class Snake {
    //HERE
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

    void setHeadColor(const sf::Color headColor);
    void setLeftEyeColor(const sf::Color leftEyeColor);
    void setRightEyeColor(const sf::Color rightEyeColor);
    void setTailColor(const sf::Color tailColor);
    Point getBody(unsigned int index);
    Direction getFaceDirection();
    Point getHead();
    Point getLookedPoint();
    sf::Color getHeadColor();
    sf::Color getLeftEyeColor();
    sf::Color getRightEyeColor();
    sf::Color getTailColor();
    void moveTo(const Point point);
    void moveTo(int x, int y);
    void eat(const Point point);
    void eat(int x, int y);
    size_t getSize();
    void turnFace(Direction direction);
    bool isPointOnBody(Point point);
    void reset();
};

#endif
