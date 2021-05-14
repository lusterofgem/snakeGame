#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameHandler.hpp"
#include "EventHandler.hpp"
#include "ViewHandler.hpp"

// MVC: Model-View-Control
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    GameHandler gameHandler(&window);
    ViewHandler viewHandler(&window, &gameHandler);
    EventHandler eventHandler(&window, &gameHandler);

    gameHandler.join();

    return 0;
}
