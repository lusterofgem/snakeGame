#include <Point.hpp>

Point::Point() {

}

Point::Point(unsigned int x, unsigned int y)
:x(x)
,y(y){

}

bool Point::operator==(Point point) {
    if(x==point.x && y==point.y) {
        return true;
    }
    else {
        return false;
    }
}
