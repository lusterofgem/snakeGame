#include <Point.hpp>

Point::Point() {

}

Point::Point(int x, int y)
:x(x)
,y(y){

}

void Point::addX(int x) {
    this->x += x;
}

void Point::addY(int y) {
    this->y += y;
}

void Point::addXY(int x, int y) {
    this->x += x;
    this->y += y;
}

bool Point::operator==(Point point) {
    if(x==point.x && y==point.y) {
        return true;
    }
    else {
        return false;
    }
}
