cmake_minimum_required(VERSION 3.16)
project(snakeGame)

# SFML
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "~/lib/SFML-2.5.1/build/")
find_package(SFML COMPONENTS graphics audio window)

# executable
add_executable(snakeGame
               src/snakeGame
               src/GameHandler
               src/ViewHandler
               src/EventHandler
               src/Map
               src/Snake
               src/Fruit
               src/Point)

# include
target_include_directories(snakeGame
                           PRIVATE include)

# lib
target_link_libraries(snakeGame
                      PRIVATE sfml-graphics
                      PRIVATE sfml-audio
                      PRIVATE sfml-window)
