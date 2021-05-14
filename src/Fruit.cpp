#include "Fruit.hpp"

Fruit::Fruit()
:point() {

}

Fruit::Fruit(Point point)
:point(point) {
}

void Fruit::setColor(sf::Color color) {
    this->color = color;
}

void Fruit::setPoint(Point point) {
    this->point = point;
}

sf::Color Fruit::getColor() {
    return color;
}

Point Fruit::getPoint() {
    return point;
}
