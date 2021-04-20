#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "snakeGame.hpp"
#include "Snake.hpp"

// Setting
const unsigned int MAP_WIDTH = 600;
const unsigned int MAP_HEIGHT = 800;
const float UNIT_WIDTH = 50.F;
const float UNIT_HEIGHT = 50.F;

int main() {
    // main window
    sf::RenderWindow window(sf::VideoMode(MAP_HEIGHT,MAP_WIDTH), "Main Window");

    // vertical synchronization
    window.setVerticalSyncEnabled(true);

    Snake snake({Point(5,5), Point(5,6), Point(5,7), Point(5,8), Point(8,8), Point(0,0)});

    // main loop
    while(window.isOpen()) {
        sf::Event event;
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
                        goNorth(snake);
                        std::cout << snake.getSize() << std::endl;

                        break;
                    }
                    case sf::Keyboard::Key::A: {
                        std::cout << "A" << std::endl;
                        snake.turnFace(Direction::EAST);
                        goEast(snake);
                        break;
                    }
                    case sf::Keyboard::Key::S: {
                        std::cout << "S" << std::endl;
                        snake.turnFace(Direction::SOUTH);
                        goSouth(snake);
                        break;
                    }
                    case sf::Keyboard::Key::D: {
                        std::cout << "D" << std::endl;
                        snake.turnFace(Direction::WEST);
                        goWest(snake);
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
                        snake.turnFace(Direction::EAST);
                        break;
                    }
                    case sf::Keyboard::Key::Right: {
                        std::cout << "Right" << std::endl;
                        snake.turnFace(Direction::WEST);
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
    for(int i=0; i<snake.getSize(); i++) {
        sf::RectangleShape rectangle(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
        Point p = snake.getBodyPoint(i);
        // std::cout << "snake[" << i << "]=Point(" << p.x << ", " << p.y << ")" << std::endl; ///////
        rectangle.move(p.x*UNIT_WIDTH, p.y*UNIT_HEIGHT);
        window.draw(rectangle);
    }
}

// sf::Vector2u getMapSize() {
//
// }

// check if the given point is in map boundary
bool isPointInMap(const Point &point) {
    const unsigned int MAP_SIZE_X = MAP_WIDTH/UNIT_WIDTH;
    const unsigned int MAP_SIZE_Y = MAP_HEIGHT/UNIT_HEIGHT;

    if(point.x>=0 && point.x<MAP_SIZE_X && point.y>=0 && point.y<MAP_SIZE_Y) { // ERROR!
        return true;
    }
    else {
        return false;
    }
}

void goNorth(Snake &snake) {
    if(snake.getSize()<1) return;

    Point targetPoint(snake.getHead().x, snake.getHead().y-1);
    if(isPointInMap(targetPoint) && !snake.isPointOnSnake(targetPoint)) {
        snake.moveTo(targetPoint);
    }
}

void goEast(Snake &snake) {
    if(snake.getSize()<1) return;

    Point targetPoint(snake.getHead().x-1, snake.getHead().y);
    if(isPointInMap(targetPoint) && !snake.isPointOnSnake(targetPoint)) {
        snake.moveTo(targetPoint);
    }
}

void goSouth(Snake &snake) {
    if(snake.getSize()<1) return;

    Point targetPoint(snake.getHead().x, snake.getHead().y+1);
    if(isPointInMap(targetPoint) && !snake.isPointOnSnake(targetPoint)) {
        snake.moveTo(targetPoint);
    }
}

void goWest(Snake &snake) {
    if(snake.getSize()<1) return;

    Point targetPoint(snake.getHead().x+1, snake.getHead().y);
    if(isPointInMap(targetPoint) && !snake.isPointOnSnake(targetPoint)) {
        snake.moveTo(targetPoint);
    }
}
