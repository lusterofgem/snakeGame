#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <thread>
#include "Snake.hpp"
#include "Fruit.hpp"

class Game {
    Snake snake;
    Fruit fruit;

    const unsigned int &MAP_WIDTH = 800;
    const unsigned int MAP_HEIGHT = 600;
    const float UNIT_WIDTH = 25.f;
    const float UNIT_HEIGHT = 25.f;
    const unsigned int TIMER_MILLISECOND = 100;

public:
    Game();
    static int getRandomNumber(int min, int max);
    void generateRandomFruit();
    void setSnake(Snake snake);
    Snake& getSnake();
    void setFruit(Fruit fruit);
    Fruit& getFruit();
};

#endif
