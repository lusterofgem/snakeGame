#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/System/Vector2.hpp>
#include "Point.hpp"

class Map {
    unsigned int x;
    unsigned int y;

public:
    Map(unsigned int x, unsigned int y);
    void setSize(unsigned int x, unsigned int y);
    void setSize(sf::Vector2u size);
    sf::Vector2u getSize();
    unsigned int getArea();
    bool isPointInMap(const Point point);
};

#endif
