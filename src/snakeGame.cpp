#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameHandler.hpp"
#include "EventHandler.hpp"
#include "ViewHandler.hpp"
#include <iostream>
#include <mutex>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    std::mutex windowMutex;
    GameHandler gameHandler(window);
    EventHandler eventHandler(window, windowMutex, gameHandler);
    ViewHandler viewHandler(window, windowMutex, gameHandler);
    gameHandler.join();
    eventHandler.join();
    viewHandler.join();

    return 0;
}
