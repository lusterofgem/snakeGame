cmake_minimum_required(VERSION 3.16)
project(snakeGame VERSION 1.0.0 LANGUAGES CXX)

# SFML
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ~/lib/SFML-2.5.1/)
find_library(SFML_LIB SFML)
find_package(SFML 2.5 COMPONENTS
             graphics
             audio
             window
             REQUIRED)

# executable
add_executable(snakeGame
               src/snakeGame
               src/Snake)

# include
target_include_directories(snakeGame
                           PRIVATE include)

# lib
target_link_libraries(snakeGame
                      PRIVATE sfml-graphics
                      PRIVATE sfml-audio
                      PRIVATE sfml-window)
