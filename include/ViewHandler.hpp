#ifndef VIEWHANDLER_HPP
#define VIEWHANDLER_HPP

#include <thread>
#include <mutex>
#include <SFML/Window.hpp>
#include "GameHandler.hpp"
#include "EventHandler.hpp"

class ViewHandler {
    sf::RenderWindow *windowPtr;
    std::mutex *windowMutexPtr;
    GameHandler *gameHandlerPtr;
    std::thread viewHandlerThread = std::thread(&ViewHandler::runLoop, this);
    unsigned int timerMillisecond = 100;

public:
    ViewHandler(sf::RenderWindow &window, std::mutex &windowMutex, GameHandler &gameHandler);
    void join();

private:
    void run();
    void runLoop();
    void drawSnake(sf::RenderWindow &window, Snake &snake);
    void drawFruit(sf::RenderWindow &window, Fruit &fruit);
};

#endif
