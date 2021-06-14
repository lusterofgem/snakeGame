#include "GameHandler.hpp"
#include <cstdlib>
#include <ctime>

GameHandler::GameHandler(sf::RenderWindow &window)
:windowPtr(&window)
,map(32, 24) {
    // Set rand seed
    std::srand(std::time(nullptr));
    reset();
}

void GameHandler::setMap(Map map) {
    this->map = map;
}

// Set the snake to current game handler
void GameHandler::setSnake(Snake snake) {
    this->snake = snake;
}

// Set the fruit to current game handler
void GameHandler::setFruit(Fruit fruit) {
    this->fruit = fruit;
}

// Get the snake from current game handler
Snake& GameHandler::getSnake() {
    return snake;
}

// Get the fruit from current game handler
Fruit& GameHandler::getFruit() {
    return fruit;
}

// Get the map from current game handler
Map& GameHandler::getMap() {
    return map;
}

void GameHandler::join() {
    gameHandlerThread.join();
}

bool GameHandler::isGameOver() {
    return gameOver;
}

bool GameHandler::isPaused() {
    return paused;
}

void GameHandler::tryToPause() {
    if(!gameOver) {
        paused = !paused;
    }
    else {
        reset();
    }
}

void GameHandler::reset() {
    paused = true;
    gameOver = false;
    generateFruit();
    resetSnake();
}

void GameHandler::run() {
    if(!gameOver && !paused) {
        // move snake
        Point targetPoint = snake.getLookedPoint();
        if(map.isPointInMap(targetPoint) && !snake.isPointOnBody(targetPoint)) {
            if(targetPoint == fruit.getPoint()) {
                snake.eat(targetPoint);
                generateFruit();
            }
            else {
                snake.moveTo(targetPoint);
            }
        }
        else {
            gameOver = true;
        }
    }
}

void GameHandler::runLoop() {
    while(windowPtr->isOpen()) {
        run();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Try to generate a fruit, if there are no space for fruit to generate, the fruit position will become (-1,-1)
void GameHandler::generateFruit() {
    // If there are no any space for fruit to generate
    if(snake.getSize()==map.getArea()) {
        fruit = Point(-1,-1);
        return;
    }
    // Generate a new fruit
    Point fruitPoint;
    do {
        fruitPoint = Point(std::rand()%(map.getSize().x-1), std::rand()%(map.getSize().y-1));
    } while(snake.isPointOnBody(fruitPoint));
    // std::cout << "GG" << std::endl;
    fruit.setPoint(fruitPoint);
}

void GameHandler::resetSnake() {
    snake = Snake({Point(map.getSize().x/2,map.getSize().y/2), Point(map.getSize().x/2,map.getSize().y/2+1), Point(map.getSize().x/2,map.getSize().y/2+2)});
}
