#include "Game.hpp"

Game::Game() {

}

int Game::getRandomNumber(int min, int max) {
    std::cout << std::rand() << " " << std::rand() << std::endl;
    return 0;
}

void Game::generateRandomFruit() {
    int mapSizeX = MAP_WIDTH/UNIT_WIDTH;
    int mapSizeY = MAP_HEIGHT/UNIT_HEIGHT;
    Point fruitPoint = Point(getRandomNumber(1, mapSizeX-1), getRandomNumber(1, mapSizeY-1));
    while(snake.isPointOnBody(fruit.getPoint())) {
        fruitPoint = Point(getRandomNumber(1, mapSizeX-1), getRandomNumber(1, mapSizeY-1));
    }
    fruit = Fruit(fruitPoint);
}

void Game::setSnake(Snake snake) {
    this->snake = snake;
}

Snake& Game::getSnake() {
    return snake;
}

void Game::setFruit(Fruit fruit) {
    this->fruit = fruit;
}

Fruit& Game::getFruit() {
    return fruit;
}
