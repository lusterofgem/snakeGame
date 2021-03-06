#include "Snake.hpp"

Snake::Snake()
:body() {

}

Snake::Snake(std::vector<Point> body)
:body(body) {

}

//
Snake::Snake(std::initializer_list<Point> points)
:body(points) {

}

void Snake::setHeadColor(const sf::Color headColor) {
    this->headColor = headColor;
}

void Snake::setLeftEyeColor(const sf::Color leftEyeColor) {
    this->leftEyeColor = leftEyeColor;
}

void Snake::setRightEyeColor(const sf::Color rightEyeColor) {
    this->rightEyeColor = rightEyeColor;
}

void Snake::setTailColor(const sf::Color tailColor) {
    this->tailColor = tailColor;
}

void Snake::setDeadColor(const sf::Color deadColor) {
    this->deadColor = deadColor;
}

Point Snake::getBody(unsigned int index) {
    return body[index];
}

Direction Snake::getFaceDirection() {
    return faceDirection;
}

// return head point, if the size < 1 (no head) return a Point(-1, -1)
Point Snake::getHead() {
    if(body.size()<1) return Point(-1,-1);
    return body[0];
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

sf::Color Snake::getHeadColor() {
    return headColor;
}

sf::Color Snake::getLeftEyeColor() {
    return leftEyeColor;
}

sf::Color Snake::getRightEyeColor() {
    return rightEyeColor;
}

sf::Color Snake::getTailColor() {
    return tailColor;
}

sf::Color Snake::getDeadColor() {
    return deadColor;
}

void Snake::moveTo(const Point point) {
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
void Snake::eat(const Point point) {
    body.push_back(Point());
    moveTo(point);
}

void Snake::eat(int x, int y) {
    eat(Point(x,y));
}

size_t Snake::getSize() {
    return body.size();
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

bool Snake::isPointOnBody(Point point) {
    for(auto it=body.begin(); it!=body.end(); it++) {
        if(point == *it) {
            return true;
        }
    }
    return false;
}

// Empty the snake body
void Snake::reset() {
    body.clear();
}
