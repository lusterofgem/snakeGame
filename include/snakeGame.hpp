#ifndef SNAKEGAME_HPP
#define SNAKEGAME_HPP

#include "Snake.hpp"
#include "Fruit.hpp"

void drawSnake(sf::RenderWindow &window, Snake &snake);
void drawFruit(sf::RenderWindow &window, Fruit &fruit);
Point getRandomFruitPoint();
bool isPointInMap(const Point point);
Point generateFruit();

#endif
