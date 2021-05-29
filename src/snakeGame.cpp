#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameHandler.hpp"
#include "EventHandler.hpp"
#include "ViewHandler.hpp"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    bool windowLock = false;
    GameHandler gameHandler(window);
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    EventHandler eventHandler(window, windowLock, gameHandler);
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    ViewHandler viewHandler(window, windowLock, gameHandler);
    // std::cout << "Ready" << std::endl;
    gameHandler.join();

    return 0;
}
