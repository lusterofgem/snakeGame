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
void Snake::eat(const Point &point) {
    body.push_back(Point());
    moveTo(point);
}

void Snake::eat(int x, int y) {
    eat(Point(x,y));
}

size_t Snake::getSize() {
    return body.size();
}

// empty snake body
void Snake::reset() {
    body.clear();
}

Point Snake::getBody(unsigned int index) {
    return body[index];
}

// try to turn face to given direction
void Snake::turnFace(Direction direction) {
    if(body.size() > 1) {
        switch(direction) {
            case Direction::NORTH: {
                if(body[1].y != body[0].y-1) {
                    // std::cout << "turnFace(Direction::NORTH) successed" << std::endl;
                    faceDirection = direction;
                }
                break;
            }
            case Direction::WEST: {
                if(body[1].x != body[0].x-1) {
                    // std::cout << "turnFace(Direction::WEST) successed" << std::endl;
                    faceDirection = direction;
                }
                break;
            }
            case Direction::SOUTH: {
                if(body[1].y != body[0].y+1) {
                    // std::cout << "turnFace(Direction::SOUTH) successed" << std::endl;
                    faceDirection = direction;
                }
                break;
            }
            case Direction::EAST: {
                if(body[1].x != body[0].x+1) {
                    // std::cout << "turnFace(Direction::EAST) successed" << std::endl;
                    faceDirection = direction;
                }
                break;
            }
        }
    }
}

Direction Snake::getFaceDirection() {
    return faceDirection;
}

// return head point, if the size < 1 (no head) return a Point(-1, -1)
Point Snake::getHead() {
    if(body.size()<1) return Point(-1,-1);
    return body[0];
}

bool Snake::isPointOnBody(Point &point) {
    for(auto it=body.begin(); it!=body.end(); it++) {
        if(point == *it) {
            return true;
        }
    }
    return false;
}

// if no direction is set, return Point(-1, -1)
Point Snake::getLookedPoint() {
    switch(faceDirection) {
        case Direction::NORTH: {
            return Point(getHead().x, getHead().y-1);
            break;
        }
        case Direction::WEST: {
            return Point(getHead().x-1, getHead().y);
            break;
        }
        case Direction::SOUTH: {
            return Point(getHead().x, getHead().y+1);
            break;
        }
        case Direction::EAST: {
            return Point(getHead().x+1, getHead().y);
            break;
        }
        default: {
            return Point(-1, -1);
        }
    }
}

// debug
void Snake::printFaceDirection() {
    switch(faceDirection) {
        case Direction::NORTH: {
            // std::cout << "snake face direction: NORTH" << std::endl;
            break;
        }
        case Direction::EAST: {
            // std::cout << "snake face direction: EAST" << std::endl;
            break;
        }
        case Direction::SOUTH: {
            // std::cout << "snake face direction: SOUTH" << std::endl;
            break;
        }
        case Direction::WEST: {
            // std::cout << "snake face direction: WEST" << std::endl;
            break;
        }
    }
}
