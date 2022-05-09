cmake_minimum_required(VERSION 3.16)
project(snakeGame)

# SFML
#set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML-2.5.1/build/")
find_package(SFML COMPONENTS graphics audio window)

# executable
add_executable(snakeGame
               src/snakeGame.cpp
               src/GameHandler.cpp
               src/ViewHandler.cpp
               src/EventHandler.cpp
               src/Map.cpp
               src/Snake.cpp
               src/Fruit.cpp
               src/Point.cpp)

# include
target_include_directories(snakeGame
                           PRIVATE include)

# lib
target_link_libraries(snakeGame
                      PRIVATE sfml-graphics
                      PRIVATE sfml-audio
                      PRIVATE sfml-window)
