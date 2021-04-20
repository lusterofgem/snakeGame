#include "Snake.hpp"
#include "Point.hpp"
#include <iostream>

Snake::Snake() {

}

Snake::Snake(std::vector<Point> body) {
    this->body = body;
}

Snake::Snake(std::initializer_list<Point> points) {
    for(auto it=points.begin(); it!=points.end(); it++) {
        body.push_back(*it);
    }
}

void Snake::moveTo(const Point &point) {
    if(body.size()<1) return;
    for(auto it=body.end()-1; it!=body.begin(); it--) {
        *it = *(it-1);
    }
    body[0] = point;
}

void Snake::moveTo(int x, int y) {
    moveTo(Point(x,y));
}

// eat and grow up
void Snake::eat(int x, int y) {
    body.push_back(Point());
    moveTo(x, y);
}

size_t Snake::getSize() {
    return body.size();
}

// empty snake body
void Snake::reset() {
    body.clear();
}

Point Snake::getBodyPoint(unsigned int index) {
    return body[index];
}

// try to turn face to given direction
void Snake::turnFace(Direction direction) {
    if(body.size() > 1) {
        switch(direction) {
            case Direction::NORTH: {
                if(body[1].y == body[0].y-1) {
                    return;
                }
            }
            case Direction::EAST: {
                if(body[1].x == body[0].x-1) {
                    return;
                }
            }
            case Direction::SOUTH: {
                if(body[1].y == body[0].y+1) {
                    return;
                }
            }
            case Direction::WEST: {
                if(body[1].x == body[0].x+1) {
                    return;
                }
            }
        }
    }
    faceDirection = direction;
}

Direction Snake::getFaceDirection() {
    return faceDirection;
}

// return head point, if the size < 1 (no head) return a Point(-1, -1)
Point Snake::getHead() {
    if(body.size()<1) return Point(-1,-1);
    return body[0];
}

bool Snake::isPointOnSnake(Point &point) {
    for(auto it=body.begin(); it!=body.end(); it++) {
        if(point == *it) {
            return true;
        }
    }
    return false;
}

// debug
void Snake::printFaceDirection() {
    switch(faceDirection) {
        case Direction::NORTH: {
            std::cout << "snake face direction: NORTH" << std::endl;
            break;
        }
        case Direction::EAST: {
            std::cout << "snake face direction: EAST" << std::endl;
            break;
        }
        case Direction::SOUTH: {
            std::cout << "snake face direction: SOUTH" << std::endl;
            break;
        }
        case Direction::WEST: {
            std::cout << "snake face direction: WAST" << std::endl;
            break;
        }
    }
}
