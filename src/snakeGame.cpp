#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "snakeGame.hpp"
#include "Snake.hpp"

// Game setting
const unsigned int MAP_WIDTH = 800;
const unsigned int MAP_HEIGHT = 600;
const float UNIT_WIDTH = 25.f;
const float UNIT_HEIGHT = 25.f;
const unsigned int TIMER_MILLISECOND = 100;

// Color
const sf::Color &SNAKE_HEAD_COLOR = sf::Color(250,250,250);
const sf::Color &SNAKE_TAIL_COLOR = sf::Color(150,150,150);
const sf::Color &SNAKE_LEFT_EYE_COLOR = sf::Color(255,255,0);
const sf::Color &SNAKE_RIGHT_EYE_COLOR = sf::Color(255,255,0);

int main() {
    // main window
    sf::RenderWindow window(sf::VideoMode(MAP_WIDTH,MAP_HEIGHT), "Main Window");

    // vertical synchronization
    window.setVerticalSyncEnabled(true);

    // Default snake
    Snake snake({Point(5,5), Point(5,6), Point(5,7), Point(5,8), Point(5,9), Point(5,10)});

    // Game timer
    sf::Clock clock;


    // main loop
    while(window.isOpen()) {
        sf::Event event;
        sf::Time time = clock.getElapsedTime();
        // move snake
        if(time.asMilliseconds()>TIMER_MILLISECOND) {
            // std::cout << "Tick" << std::endl; //
            Point targetPoint = snake.getLookedPoint();
            if(isPointInMap(targetPoint) && !snake.isPointOnBody(targetPoint)) {
                snake.printFaceDirection();
                snake.moveTo(targetPoint);
                // std::cout << targetPoint.x << " " << targetPoint.y << std::endl;
            }
            clock.restart();
        }
        // get events and run each event
        while(window.pollEvent(event)) {
            // close window event
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            // key event
            else if(event.type == sf::Event::KeyPressed) {
                switch(event.key.code) {
                    case sf::Keyboard::Key::W: {
                        std::cout << "W" << std::endl;
                        snake.turnFace(Direction::NORTH);

                        break;
                    }
                    case sf::Keyboard::Key::A: {
                        std::cout << "A" << std::endl;
                        snake.turnFace(Direction::WEST);
                        break;
                    }
                    case sf::Keyboard::Key::S: {
                        std::cout << "S" << std::endl;
                        snake.turnFace(Direction::SOUTH);
                        break;
                    }
                    case sf::Keyboard::Key::D: {
                        std::cout << "D" << std::endl;
                        snake.turnFace(Direction::EAST);
                        break;
                    }
                    case sf::Keyboard::Key::Space: {
                        std::cout << "Space" << std::endl;

                        break;
                    }
                    case sf::Keyboard::Key::Up: {
                        std::cout << "Up" << std::endl;
                        snake.turnFace(Direction::NORTH);
                        break;
                    }
                    case sf::Keyboard::Key::Down: {
                        std::cout << "Down" << std::endl;
                        snake.turnFace(Direction::SOUTH);
                        break;
                    }
                    case sf::Keyboard::Key::Left: {
                        std::cout << "Left" << std::endl;
                        snake.turnFace(Direction::WEST);
                        break;
                    }
                    case sf::Keyboard::Key::Right: {
                        std::cout << "Right" << std::endl;
                        snake.turnFace(Direction::EAST);
                        break;
                    }
                    case sf::Keyboard::Key::Enter: {
                        std::cout << "Enter" << std::endl;
                        break;
                    }
                }
            }
        }
        window.clear();
        drawSnake(window, snake);
        window.display();
    }

    return 0;
}

void drawSnake(sf::RenderWindow &window, Snake &snake) {
    if(snake.getSize()<1) return;

    // draw snake head
    sf::RectangleShape headRectangle(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
    headRectangle.setFillColor(SNAKE_HEAD_COLOR);
    headRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
    window.draw(headRectangle);

    // draw snake eye
    switch(snake.getFaceDirection()) {
        case Direction::NORTH: {
            sf::RectangleShape leftEyeRectangle(sf::Vector2f(UNIT_WIDTH/5, UNIT_HEIGHT/5*2));
            sf::RectangleShape rightEyeRectangle(sf::Vector2f(UNIT_WIDTH/5, UNIT_HEIGHT/5*2));
            leftEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
            rightEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
            leftEyeRectangle.move(UNIT_WIDTH/5, UNIT_HEIGHT/5);
            rightEyeRectangle.move(UNIT_WIDTH/5*3, UNIT_HEIGHT/5);
            leftEyeRectangle.setFillColor(SNAKE_LEFT_EYE_COLOR);
            rightEyeRectangle.setFillColor(SNAKE_RIGHT_EYE_COLOR);
            window.draw(leftEyeRectangle);
            window.draw(rightEyeRectangle);
            break;
        }
        case Direction::WEST: {
            sf::RectangleShape leftEyeRectangle(sf::Vector2f(UNIT_WIDTH/5*2, UNIT_HEIGHT/5));
            sf::RectangleShape rightEyeRectangle(sf::Vector2f(UNIT_WIDTH/5*2, UNIT_HEIGHT/5));
            leftEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
            rightEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
            leftEyeRectangle.move(UNIT_WIDTH/5, UNIT_HEIGHT/5*3);
            rightEyeRectangle.move(UNIT_WIDTH/5, UNIT_HEIGHT/5);
            leftEyeRectangle.setFillColor(SNAKE_LEFT_EYE_COLOR);
            rightEyeRectangle.setFillColor(SNAKE_RIGHT_EYE_COLOR);
            window.draw(leftEyeRectangle);
            window.draw(rightEyeRectangle);
            break;
        }
        case Direction::SOUTH: {
            sf::RectangleShape leftEyeRectangle(sf::Vector2f(UNIT_WIDTH/5, UNIT_HEIGHT/5*2));
            sf::RectangleShape rightEyeRectangle(sf::Vector2f(UNIT_WIDTH/5, UNIT_HEIGHT/5*2));
            leftEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
            rightEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
            leftEyeRectangle.move(UNIT_WIDTH/5*3, UNIT_HEIGHT/5*2);
            rightEyeRectangle.move(UNIT_WIDTH/5, UNIT_HEIGHT/5*2);
            leftEyeRectangle.setFillColor(SNAKE_LEFT_EYE_COLOR);
            rightEyeRectangle.setFillColor(SNAKE_RIGHT_EYE_COLOR);
            window.draw(leftEyeRectangle);
            window.draw(rightEyeRectangle);
            break;
        }
        case Direction::EAST: {
            sf::RectangleShape leftEyeRectangle(sf::Vector2f(UNIT_WIDTH/5*2, UNIT_HEIGHT/5));
            sf::RectangleShape rightEyeRectangle(sf::Vector2f(UNIT_WIDTH/5*2, UNIT_HEIGHT/5));
            leftEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
            rightEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
            leftEyeRectangle.move(UNIT_WIDTH/5*2, UNIT_HEIGHT/5);
            rightEyeRectangle.move(UNIT_WIDTH/5*2, UNIT_HEIGHT/5*3);
            leftEyeRectangle.setFillColor(SNAKE_LEFT_EYE_COLOR);
            rightEyeRectangle.setFillColor(SNAKE_RIGHT_EYE_COLOR);
            window.draw(leftEyeRectangle);
            window.draw(rightEyeRectangle);
            break;
        }
    }

    // draw snake body (with gradual color)
    for(int i=1; i<snake.getSize()-1; i++) {
        sf::RectangleShape bodyRectangle(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
        float rDistance = (SNAKE_HEAD_COLOR.r-SNAKE_TAIL_COLOR.r)/(snake.getSize()-1); //HERE deviation
        float gDistance = (SNAKE_HEAD_COLOR.g-SNAKE_TAIL_COLOR.g)/(snake.getSize()-1);
        float bDistance = (SNAKE_HEAD_COLOR.b-SNAKE_TAIL_COLOR.b)/(snake.getSize()-1);

        bodyRectangle.setFillColor(sf::Color( SNAKE_HEAD_COLOR.r - rDistance*i
                                            , SNAKE_HEAD_COLOR.g - gDistance*i
                                            , SNAKE_HEAD_COLOR.b - bDistance*i));
        bodyRectangle.move(snake.getBody(i).x*UNIT_WIDTH, snake.getBody(i).y*UNIT_HEIGHT);
        window.draw(bodyRectangle);
    }

    // draw snake tail
    sf::RectangleShape tailRectangle(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
    tailRectangle.setFillColor(SNAKE_TAIL_COLOR);
    tailRectangle.move(snake.getBody(snake.getSize()-1).x*UNIT_WIDTH, snake.getBody(snake.getSize()-1).y*UNIT_HEIGHT);
    window.draw(tailRectangle);
}

// sf::Vector2u getMapSize() {
//
// }

// check if the given point is in map boundary
bool isPointInMap(const Point &point) {
    const unsigned int MAP_SIZE_X = MAP_WIDTH/UNIT_WIDTH;
    const unsigned int MAP_SIZE_Y = MAP_HEIGHT/UNIT_HEIGHT;

    if(point.x>=0 && point.x<MAP_SIZE_X && point.y>=0 && point.y<MAP_SIZE_Y) {
        return true;
    }
    else {
        return false;
    }
}

void goNorth(Snake &snake) {
    if(snake.getSize()<1) return;

    Point targetPoint(snake.getHead().x, snake.getHead().y-1);
    if(isPointInMap(targetPoint) && !snake.isPointOnBody(targetPoint)) {
        snake.moveTo(targetPoint);
    }
}

void goEast(Snake &snake) {
    if(snake.getSize()<1) return;

    Point targetPoint(snake.getHead().x-1, snake.getHead().y);
    if(isPointInMap(targetPoint) && !snake.isPointOnBody(targetPoint)) {
        snake.moveTo(targetPoint);
    }
}

void goSouth(Snake &snake) {
    if(snake.getSize()<1) return;

    Point targetPoint(snake.getHead().x, snake.getHead().y+1);
    if(isPointInMap(targetPoint) && !snake.isPointOnBody(targetPoint)) {
        snake.moveTo(targetPoint);
    }
}

void goWest(Snake &snake) {
    if(snake.getSize()<1) return;

    Point targetPoint(snake.getHead().x+1, snake.getHead().y);
    if(isPointInMap(targetPoint) && !snake.isPointOnBody(targetPoint)) {
        snake.moveTo(targetPoint);
    }
}
