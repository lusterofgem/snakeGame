#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "GameHandler.hpp"
#include <thread>
#include <mutex>

class EventHandler {
    sf::RenderWindow *windowPtr;
    std::mutex *windowMutexPtr;
    GameHandler *gameHandlerPtr;
    std::thread eventHandlerThread = std::thread(&EventHandler::runLoop, this);

public:
    EventHandler(sf::RenderWindow &window, std::mutex &windowMutex, GameHandler &gameHandler);
    void join();

private:
    void run();
    void runLoop();
};

#endif
