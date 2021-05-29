#include "EventHandler.hpp"

EventHandler::EventHandler(sf::RenderWindow &window, bool &windowLock, GameHandler &gameHandler)
:windowPtr(&window)
,windowLockPtr(&windowLock)
,gameHandlerPtr(&gameHandler) {

}

void EventHandler::join() {
    eventHandlerThread.join();
}

void EventHandler::run() {
    if(*windowLockPtr) {
        return;
    }
    *windowLockPtr = true;
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
                    gameHandlerPtr->getSnake().turnFace(Direction::NORTH);
                    break;
                }
                case sf::Keyboard::Key::A: {
                    gameHandlerPtr->getSnake().turnFace(Direction::WEST);
                    break;
                }
                case sf::Keyboard::Key::S: {
                    gameHandlerPtr->getSnake().turnFace(Direction::SOUTH);
                    break;
                }
                case sf::Keyboard::Key::D: {
                    gameHandlerPtr->getSnake().turnFace(Direction::EAST);
                    break;
                }
                case sf::Keyboard::Key::Space: {
                    gameHandlerPtr->tryToPause();
                    break;
                }
                case sf::Keyboard::Key::Up: {
                    gameHandlerPtr->getSnake().turnFace(Direction::NORTH);
                    break;
                }
                case sf::Keyboard::Key::Down: {
                    gameHandlerPtr->getSnake().turnFace(Direction::SOUTH);
                    break;
                }
                case sf::Keyboard::Key::Left: {
                    gameHandlerPtr->getSnake().turnFace(Direction::WEST);
                    break;
                }
                case sf::Keyboard::Key::Right: {
                    gameHandlerPtr->getSnake().turnFace(Direction::EAST);
                    break;
                }
                case sf::Keyboard::Key::Enter: {
                    gameHandlerPtr->tryToPause();
                    break;
                }
            }
        }
    }
    *windowLockPtr = false;
}

void EventHandler::runLoop() {
    while(windowPtr->isOpen()) {
        run();
    }
}
