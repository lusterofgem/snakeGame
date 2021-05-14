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

sf::Color Fruit::getColor() {
    return color;
}

void Fruit::setPoint(Point point) {
    this->point = point;
}

Point Fruit::getPoint() {
    return point;
}
