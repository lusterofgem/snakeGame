#ifndef SNAKEGAME_HPP
#define SNAKEGAME_HPP

#include <Snake.hpp>

void drawSnake(sf::RenderWindow &window, Snake &snake);
void drawFruit(sf::RenderWindow &window, Point &point);
Point getRandomFruit();
bool isPointInMap(const Point &point);
void goNorth(Snake &snake);
void goEast(Snake &snake);
void goSouth(Snake &snake);
void goWest(Snake &snake);
Point generateFruit();

#endif
