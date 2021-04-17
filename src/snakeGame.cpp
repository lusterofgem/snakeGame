#include <SFML/Window.hpp>

int main() {
    // main window
    sf::Window window(sf::VideoMode(800,600), "Main Window");
    
    // vertical synchronization
    window.setVerticalSyncEnabled(true);
    
    // main loop
    while(window.isOpen()) {
        sf::Event event;
        // get events and run each event
        while(window.pollEvent(event)) {
            // close window event
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
    
    return 0;
}
