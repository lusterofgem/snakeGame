#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameHandler.hpp"
#include "EventHandler.hpp"
#include "ViewHandler.hpp"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    GameHandler gameHandler(window);
    EventHandler eventHandler(window, gameHandler);
    ViewHandler viewHandler(window, gameHandler);
    gameHandler.join();

    return 0;
}
