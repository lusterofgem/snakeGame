#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>
#include "Point.hpp"

class Fruit {
    Point point;
    sf::Color color = sf::Color(255,0,0); // Ask

public:
    Fruit();
    Fruit(Point point);

    void setColor(sf::Color color);
    sf::Color getColor();
    void setPoint(Point point);
    Point getPoint();
};

#endif
