#ifndef VIEWHANDLER_HPP
#define VIEWHANDLER_HPP

#include <thread>
#include <SFML/Window.hpp>
#include "GameHandler.hpp"
#include "EventHandler.hpp"

class ViewHandler {
    sf::RenderWindow *windowPtr;
    GameHandler *gameHandlerPtr;
    // std::thread viewHandlerThread(&ViewHandler::runLoop, this);
    std::thread viewHandlerThread = std::thread(&ViewHandler::runLoop, this);

public:
    ViewHandler(sf::RenderWindow &window, GameHandler &gameHandler);
    void join();

private:
    void run();
    void runLoop();
    void drawSnake(sf::RenderWindow &window, Snake &snake);
    void drawFruit(sf::RenderWindow &window, Fruit &fruit);
};

#endif
