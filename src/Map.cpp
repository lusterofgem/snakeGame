#include "Map.hpp"

Map::Map(unsigned int x, unsigned int y)
:x(x)
,y(y) {

}

void Map::setSize(unsigned int x, unsigned int y) {
    this->x = x;
    this->y = y;
}

void Map::setSize(sf::Vector2u size) {
    x = size.x;
    y = size.y;
}

sf::Vector2u Map::getSize() {
    return sf::Vector2u(x,y);
}

unsigned int Map::getArea() {
    return x*y;
}

bool Map::isPointInMap(const Point point) {
    if(point.x>=0 && point.x<x && point.y>=0 && point.y<y) {
        return true;
    }
    else {
        return false;
    }
}
