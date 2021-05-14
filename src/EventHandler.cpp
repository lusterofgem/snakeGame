#include "EventHandler.hpp"

EventHandler::EventHandler(sf::RenderWindow *windowPtr, GameHandler *gameHandlerPtr)
:windowPtr(windowPtr)
,gameHandlerPtr(gameHandlerPtr) {

}

void EventHandler::join() {
    eventHandlerThread.join();
}

void EventHandler::run() {
    sf::Event event;
    while(windowPtr->pollEvent(event)) {
        // Close window event
        if(event.type == sf::Event::Closed) {
            windowPtr->close();
        }
        // Key event
        else if(event.type == sf::Event::KeyPressed) {
            switch(event.key.code) {
                case sf::Keyboard::Key::W: {
                    std::cout << "W" << std::endl;
                    gameHandlerPtr->getSnake().turnFace(Direction::NORTH);

                    break;
                }
                case sf::Keyboard::Key::A: {
                    std::cout << "A" << std::endl;
                    gameHandlerPtr->getSnake().turnFace(Direction::WEST);
                    break;
                }
                case sf::Keyboard::Key::S: {
                    std::cout << "S" << std::endl;
                    gameHandlerPtr->getSnake().turnFace(Direction::SOUTH);
                    break;
                }
                case sf::Keyboard::Key::D: {
                    std::cout << "D" << std::endl;
                    gameHandlerPtr->getSnake().turnFace(Direction::EAST);
                    break;
                }
                case sf::Keyboard::Key::Space: {
                    std::cout << "Space" << std::endl;

                    break;
                }
                case sf::Keyboard::Key::Up: {
                    std::cout << "Up" << std::endl;
                    gameHandlerPtr->getSnake().turnFace(Direction::NORTH);
                    break;
                }
                case sf::Keyboard::Key::Down: {
                    std::cout << "Down" << std::endl;
                    gameHandlerPtr->getSnake().turnFace(Direction::SOUTH);
                    break;
                }
                case sf::Keyboard::Key::Left: {
                    std::cout << "Left" << std::endl;
                    gameHandlerPtr->getSnake().turnFace(Direction::WEST);
                    break;
                }
                case sf::Keyboard::Key::Right: {
                    std::cout << "Right" << std::endl;
                    gameHandlerPtr->getSnake().turnFace(Direction::EAST);
                    break;
                }
                case sf::Keyboard::Key::Enter: {
                    std::cout << "Enter" << std::endl;
                    break;
                }
                case sf::Keyboard::Key::Escape: {
                    std::cout << "Escape" << std::endl;
                }
            }
        }
    }
}

void EventHandler::runLoop() {
    while(windowPtr->isOpen()) {
        run();
    }
}
