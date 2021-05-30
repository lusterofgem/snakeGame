#include "ViewHandler.hpp"
// #include <iostream>

// Default Constructor
ViewHandler::ViewHandler(sf::RenderWindow &window, bool &windowLock, GameHandler &gameHandler)
:windowPtr(&window)
,windowLockPtr(&windowLock)
,gameHandlerPtr(&gameHandler) {
    windowPtr->setVerticalSyncEnabled(true);
}

// Start view handler thread
void ViewHandler::join() {
    viewHandlerThread.join();
}

// Refresh game screen
void ViewHandler::run() {
    if(*windowLockPtr) {
        // std::cout << *windowLockPtr << std::endl;
        return;
    }
    // std::cout << *windowLockPtr << std::endl;
    *windowLockPtr = true;
    windowPtr->clear();
    drawSnake(*windowPtr, gameHandlerPtr->getSnake());
    drawFruit(*windowPtr, gameHandlerPtr->getFruit());
    windowPtr->display(); ///////////////////////////////Crash
    *windowLockPtr = false;
}

void ViewHandler::runLoop() {
    while(windowPtr->isOpen()) {
        run();
    }
}

// Draw given snake on window
void ViewHandler::drawSnake(sf::RenderWindow &window, Snake &snake) {
    if(snake.getSize()<1) return;

    ///////////////////////////////////////////////////////////////////////////////////
    const float UNIT_WIDTH = windowPtr->getSize().x/gameHandlerPtr->getMap().getSize().x;
    const float UNIT_HEIGHT = windowPtr->getSize().y/gameHandlerPtr->getMap().getSize().y;

    if(gameHandlerPtr->isGameOver()) {
        // Draw dead snake
        for(size_t i=0; i<snake.getSize(); i++) {
            sf::RectangleShape bodyRectangle(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
            bodyRectangle.setFillColor(snake.getDeadColor());
            bodyRectangle.move(snake.getBody(i).x*UNIT_WIDTH, snake.getBody(i).y*UNIT_HEIGHT);
            window.draw(bodyRectangle);
        }
    }
    else if(gameHandlerPtr->isPaused()) {
        // Draw paused snake head
        sf::RectangleShape headRectangle(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
        sf::Color headColor(snake.getHeadColor());
        headColor.a = 255/2;
        headRectangle.setFillColor(headColor);
        headRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
        window.draw(headRectangle);

        // Draw paused snake eye
        switch(snake.getFaceDirection()) {
            case Direction::NORTH: {
                sf::RectangleShape leftEyeRectangle(sf::Vector2f(UNIT_WIDTH/5, UNIT_HEIGHT/5*2));
                sf::RectangleShape rightEyeRectangle(sf::Vector2f(UNIT_WIDTH/5, UNIT_HEIGHT/5*2));
                leftEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                rightEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                leftEyeRectangle.move(UNIT_WIDTH/5, UNIT_HEIGHT/5);
                rightEyeRectangle.move(UNIT_WIDTH/5*3, UNIT_HEIGHT/5);
                leftEyeRectangle.setFillColor(snake.getLeftEyeColor());
                rightEyeRectangle.setFillColor(snake.getRightEyeColor());
                window.draw(leftEyeRectangle);
                window.draw(rightEyeRectangle);
                break;
            }
            case Direction::WEST: {
                sf::RectangleShape leftEyeRectangle(sf::Vector2f(UNIT_WIDTH/5*2, UNIT_HEIGHT/5));
                sf::RectangleShape rightEyeRectangle(sf::Vector2f(UNIT_WIDTH/5*2, UNIT_HEIGHT/5));
                leftEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                rightEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                leftEyeRectangle.move(UNIT_WIDTH/5, UNIT_HEIGHT/5*3);
                rightEyeRectangle.move(UNIT_WIDTH/5, UNIT_HEIGHT/5);
                leftEyeRectangle.setFillColor(snake.getLeftEyeColor());
                rightEyeRectangle.setFillColor(snake.getRightEyeColor());
                window.draw(leftEyeRectangle);
                window.draw(rightEyeRectangle);
                break;
            }
            case Direction::SOUTH: {
                sf::RectangleShape leftEyeRectangle(sf::Vector2f(UNIT_WIDTH/5, UNIT_HEIGHT/5*2));
                sf::RectangleShape rightEyeRectangle(sf::Vector2f(UNIT_WIDTH/5, UNIT_HEIGHT/5*2));
                leftEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                rightEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                leftEyeRectangle.move(UNIT_WIDTH/5*3, UNIT_HEIGHT/5*2);
                rightEyeRectangle.move(UNIT_WIDTH/5, UNIT_HEIGHT/5*2);
                leftEyeRectangle.setFillColor(snake.getLeftEyeColor());
                rightEyeRectangle.setFillColor(snake.getRightEyeColor());
                window.draw(leftEyeRectangle);
                window.draw(rightEyeRectangle);
                break;
            }
            case Direction::EAST: {
                sf::RectangleShape leftEyeRectangle(sf::Vector2f(UNIT_WIDTH/5*2, UNIT_HEIGHT/5));
                sf::RectangleShape rightEyeRectangle(sf::Vector2f(UNIT_WIDTH/5*2, UNIT_HEIGHT/5));
                leftEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                rightEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                leftEyeRectangle.move(UNIT_WIDTH/5*2, UNIT_HEIGHT/5);
                rightEyeRectangle.move(UNIT_WIDTH/5*2, UNIT_HEIGHT/5*3);
                leftEyeRectangle.setFillColor(snake.getLeftEyeColor());
                rightEyeRectangle.setFillColor(snake.getRightEyeColor());
                window.draw(leftEyeRectangle);
                window.draw(rightEyeRectangle);
                break;
            }
        }

        // Draw paused snake body (with gradual color)
        for(size_t i=1; i<snake.getSize()-1; i++) {
            sf::RectangleShape bodyRectangle(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
            float rDistance = (snake.getHeadColor().r-snake.getTailColor().r)/static_cast<float>(snake.getSize()-1);
            float gDistance = (snake.getHeadColor().g-snake.getTailColor().g)/static_cast<float>(snake.getSize()-1);
            float bDistance = (snake.getHeadColor().b-snake.getTailColor().b)/static_cast<float>(snake.getSize()-1);

            bodyRectangle.setFillColor(sf::Color( snake.getHeadColor().r - rDistance*i
                                                , snake.getHeadColor().g - gDistance*i
                                                , snake.getHeadColor().b - bDistance*i
                                                , 255/2));
            bodyRectangle.move(snake.getBody(i).x*UNIT_WIDTH, snake.getBody(i).y*UNIT_HEIGHT);
            window.draw(bodyRectangle);
        }

        // Draw paused snake tail
        sf::RectangleShape tailRectangle(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
        sf::Color tailColor(snake.getTailColor());
        tailColor.a = 255/2;
        tailRectangle.setFillColor(tailColor);
        tailRectangle.move(snake.getBody(snake.getSize()-1).x*UNIT_WIDTH, snake.getBody(snake.getSize()-1).y*UNIT_HEIGHT);
        window.draw(tailRectangle);
    }
    else {
        // Draw snake head
        sf::RectangleShape headRectangle(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
        headRectangle.setFillColor(snake.getHeadColor());
        headRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
        window.draw(headRectangle);

        // Draw snake eye
        switch(snake.getFaceDirection()) {
            case Direction::NORTH: {
                sf::RectangleShape leftEyeRectangle(sf::Vector2f(UNIT_WIDTH/5, UNIT_HEIGHT/5*2));
                sf::RectangleShape rightEyeRectangle(sf::Vector2f(UNIT_WIDTH/5, UNIT_HEIGHT/5*2));
                leftEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                rightEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                leftEyeRectangle.move(UNIT_WIDTH/5, UNIT_HEIGHT/5);
                rightEyeRectangle.move(UNIT_WIDTH/5*3, UNIT_HEIGHT/5);
                leftEyeRectangle.setFillColor(snake.getLeftEyeColor());
                rightEyeRectangle.setFillColor(snake.getRightEyeColor());
                window.draw(leftEyeRectangle);
                window.draw(rightEyeRectangle);
                break;
            }
            case Direction::WEST: {
                sf::RectangleShape leftEyeRectangle(sf::Vector2f(UNIT_WIDTH/5*2, UNIT_HEIGHT/5));
                sf::RectangleShape rightEyeRectangle(sf::Vector2f(UNIT_WIDTH/5*2, UNIT_HEIGHT/5));
                leftEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                rightEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                leftEyeRectangle.move(UNIT_WIDTH/5, UNIT_HEIGHT/5*3);
                rightEyeRectangle.move(UNIT_WIDTH/5, UNIT_HEIGHT/5);
                leftEyeRectangle.setFillColor(snake.getLeftEyeColor());
                rightEyeRectangle.setFillColor(snake.getRightEyeColor());
                window.draw(leftEyeRectangle);
                window.draw(rightEyeRectangle);
                break;
            }
            case Direction::SOUTH: {
                sf::RectangleShape leftEyeRectangle(sf::Vector2f(UNIT_WIDTH/5, UNIT_HEIGHT/5*2));
                sf::RectangleShape rightEyeRectangle(sf::Vector2f(UNIT_WIDTH/5, UNIT_HEIGHT/5*2));
                leftEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                rightEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                leftEyeRectangle.move(UNIT_WIDTH/5*3, UNIT_HEIGHT/5*2);
                rightEyeRectangle.move(UNIT_WIDTH/5, UNIT_HEIGHT/5*2);
                leftEyeRectangle.setFillColor(snake.getLeftEyeColor());
                rightEyeRectangle.setFillColor(snake.getRightEyeColor());
                window.draw(leftEyeRectangle);
                window.draw(rightEyeRectangle);
                break;
            }
            case Direction::EAST: {
                sf::RectangleShape leftEyeRectangle(sf::Vector2f(UNIT_WIDTH/5*2, UNIT_HEIGHT/5));
                sf::RectangleShape rightEyeRectangle(sf::Vector2f(UNIT_WIDTH/5*2, UNIT_HEIGHT/5));
                leftEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                rightEyeRectangle.move(snake.getHead().x*UNIT_WIDTH, snake.getHead().y*UNIT_HEIGHT);
                leftEyeRectangle.move(UNIT_WIDTH/5*2, UNIT_HEIGHT/5);
                rightEyeRectangle.move(UNIT_WIDTH/5*2, UNIT_HEIGHT/5*3);
                leftEyeRectangle.setFillColor(snake.getLeftEyeColor());
                rightEyeRectangle.setFillColor(snake.getRightEyeColor());
                window.draw(leftEyeRectangle);
                window.draw(rightEyeRectangle);
                break;
            }
        }

        // Draw snake body (with gradual color)
        for(size_t i=1; i<snake.getSize()-1; i++) {
            sf::RectangleShape bodyRectangle(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
            float rDistance = (snake.getHeadColor().r-snake.getTailColor().r)/static_cast<float>(snake.getSize()-1); // HERE
            float gDistance = (snake.getHeadColor().g-snake.getTailColor().g)/static_cast<float>(snake.getSize()-1);
            float bDistance = (snake.getHeadColor().b-snake.getTailColor().b)/static_cast<float>(snake.getSize()-1);

            bodyRectangle.setFillColor(sf::Color( snake.getHeadColor().r - rDistance*i
                                                , snake.getHeadColor().g - gDistance*i
                                                , snake.getHeadColor().b - bDistance*i));
            bodyRectangle.move(snake.getBody(i).x*UNIT_WIDTH, snake.getBody(i).y*UNIT_HEIGHT);
            window.draw(bodyRectangle);
        }

        // Draw snake tail
        sf::RectangleShape tailRectangle(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
        tailRectangle.setFillColor(snake.getTailColor());
        tailRectangle.move(snake.getBody(snake.getSize()-1).x*UNIT_WIDTH, snake.getBody(snake.getSize()-1).y*UNIT_HEIGHT);
        window.draw(tailRectangle);
    }
}

// Draw given fruit on window
void ViewHandler::drawFruit(sf::RenderWindow &window, Fruit &fruit) {
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    const float UNIT_WIDTH = windowPtr->getSize().x/gameHandlerPtr->getMap().getSize().x;
    const float UNIT_HEIGHT = windowPtr->getSize().y/gameHandlerPtr->getMap().getSize().y;
    sf::RectangleShape fruitRectangle(sf::Vector2f(UNIT_WIDTH, UNIT_HEIGHT));
    fruitRectangle.move(fruit.getPoint().x*UNIT_WIDTH, fruit.getPoint().y*UNIT_HEIGHT);
    fruitRectangle.setFillColor(fruit.getColor());
    window.draw(fruitRectangle);
}
