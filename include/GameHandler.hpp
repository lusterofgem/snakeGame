#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <thread>
#include "Map.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"

class GameHandler {
    sf::RenderWindow *windowPtr;
    sf::Clock clock;
    Map map;
    Snake snake;
    Fruit fruit;
    // std::thread gameHandlerThread(&GameHandler::runLoop, this);
    std::thread gameHandlerThread = std::thread(&GameHandler::runLoop, this);

    // Default color setting
    const sf::Color &SNAKE_HEAD_COLOR = sf::Color(255,100,100);
    const sf::Color &SNAKE_TAIL_COLOR = sf::Color(100,100,100);
    const sf::Color &SNAKE_LEFT_EYE_COLOR = sf::Color(255,255,0);
    const sf::Color &SNAKE_RIGHT_EYE_COLOR = sf::Color(255,255,0);
    const sf::Color &FRUIT_COLOR = sf::Color(255,0,0);

    ////////// const unsigned int &MAP_WIDTH = 800;
    // const unsigned int MAP_WIDTH = 800;
    // const unsigned int MAP_HEIGHT = 600;
    // const float UNIT_WIDTH = 25.f;
    // const float UNIT_HEIGHT = 25.f;
    const unsigned int TIMER_MILLISECOND = 100;

public:
    GameHandler(sf::RenderWindow *windowPtr);
    void setMap(Map map);
    void setSnake(Snake snake);
    void setFruit(Fruit fruit);
    Map& getMap();
    Snake& getSnake();
    Fruit& getFruit();
    void join();

private:
    void run();
    void runLoop();
    void generateFruit();
};

#endif
