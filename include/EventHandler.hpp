#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "GameHandler.hpp"
#include <thread>

class EventHandler {
    sf::RenderWindow *windowPtr;
    GameHandler *gameHandlerPtr;
    // std::thread eventHandlerThread(&EventHandler::runLoop, this);
    std::thread eventHandlerThread = std::thread(&EventHandler::runLoop, this);

public:
    EventHandler(sf::RenderWindow *windowPtr, GameHandler *gameHandlerPtr);
    void join();

private:
    void run();
    void runLoop();
};

#endif