cmake_minimum_required(VERSION 3.10)
project(snakeGame)

include_directories(~/lib/SFML-2.5.1/include)
link_directories(~lib/SFML-2.5.1/lib)

add_executable(snakeGame snakeGame.cpp)
#TARGET_LINK_LIBRARIES()
