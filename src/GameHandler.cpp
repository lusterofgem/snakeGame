#include "GameHandler.hpp"
#include <cstdlib>
#include <ctime>

GameHandler::GameHandler(sf::RenderWindow *windowPtr)
:windowPtr(windowPtr)
,clock()
,map(32, 24)
,snake()
,fruit() {
    // set rand seed
    std::srand(std::time(nullptr));

    snake = Snake({Point(5,5), Point(5,6), Point(5,7), Point(5,8), Point(5,9), Point(5,10)});
    snake.setHeadColor(SNAKE_HEAD_COLOR);
    snake.setTailColor(SNAKE_TAIL_COLOR);
    snake.setLeftEyeColor(SNAKE_LEFT_EYE_COLOR);
    snake.setRightEyeColor(SNAKE_RIGHT_EYE_COLOR);

    fruit.setColor(FRUIT_COLOR);
    generateFruit();
}

void GameHandler::join() {
    gameHandlerThread.join();
}

void GameHandler::run() {
    sf::Event event;
    sf::Time time = clock.getElapsedTime();
    // move snake
    if(time.asMilliseconds()>TIMER_MILLISECOND) {
        std::cout << "Tick" << std::endl; ///////////////////////////////////////
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
            std::cout << "Dead" << std::endl;//////////////////////////////////////////////////////
        }
        clock.restart();
    }
}

void GameHandler::runLoop() {
    while(windowPtr->isOpen()) {
        run();
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
