#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>
#include "Point.hpp"

class Fruit {
    Point point;
    sf::Color color = sf::Color(255,0,0);

public:
    Fruit();
    Fruit(Point point);

    void setColor(sf::Color color);
    void setPoint(Point point);
    sf::Color getColor();
    Point getPoint();
};

#endif
