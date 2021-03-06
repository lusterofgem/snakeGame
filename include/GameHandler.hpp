#ifndef GAME_HPP
#define GAME_HPP

#include <thread>
#include "Map.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"

class GameHandler {
    sf::RenderWindow *windowPtr;
    Map map;
    Snake snake;
    Fruit fruit;
    bool gameOver;
    bool paused;
    std::thread gameHandlerThread = std::thread(&GameHandler::runLoop, this);
    unsigned int timerMillisecond = 100;

public:
    GameHandler(sf::RenderWindow &window);
    void setMap(Map map);
    void setSnake(Snake snake);
    void setFruit(Fruit fruit);
    Map& getMap();
    Snake& getSnake();
    Fruit& getFruit();
    void join();
    bool isGameOver();
    bool isPaused();
    void tryToPause(); // reset the game if it is game over
    void reset();

private:
    void run();
    void runLoop();
    void generateFruit();
    void resetSnake();
};

#endif
