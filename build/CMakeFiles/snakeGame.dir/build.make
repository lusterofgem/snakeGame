# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kde/Desktop/lab/sfml/snakeGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kde/Desktop/lab/sfml/snakeGame/build

# Include any dependencies generated for this target.
include CMakeFiles/snakeGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/snakeGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/snakeGame.dir/flags.make

CMakeFiles/snakeGame.dir/src/snakeGame.cpp.o: CMakeFiles/snakeGame.dir/flags.make
CMakeFiles/snakeGame.dir/src/snakeGame.cpp.o: ../src/snakeGame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kde/Desktop/lab/sfml/snakeGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/snakeGame.dir/src/snakeGame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snakeGame.dir/src/snakeGame.cpp.o -c /home/kde/Desktop/lab/sfml/snakeGame/src/snakeGame.cpp

CMakeFiles/snakeGame.dir/src/snakeGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snakeGame.dir/src/snakeGame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kde/Desktop/lab/sfml/snakeGame/src/snakeGame.cpp > CMakeFiles/snakeGame.dir/src/snakeGame.cpp.i

CMakeFiles/snakeGame.dir/src/snakeGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snakeGame.dir/src/snakeGame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kde/Desktop/lab/sfml/snakeGame/src/snakeGame.cpp -o CMakeFiles/snakeGame.dir/src/snakeGame.cpp.s

CMakeFiles/snakeGame.dir/src/Snake.cpp.o: CMakeFiles/snakeGame.dir/flags.make
CMakeFiles/snakeGame.dir/src/Snake.cpp.o: ../src/Snake.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kde/Desktop/lab/sfml/snakeGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/snakeGame.dir/src/Snake.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snakeGame.dir/src/Snake.cpp.o -c /home/kde/Desktop/lab/sfml/snakeGame/src/Snake.cpp

CMakeFiles/snakeGame.dir/src/Snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snakeGame.dir/src/Snake.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kde/Desktop/lab/sfml/snakeGame/src/Snake.cpp > CMakeFiles/snakeGame.dir/src/Snake.cpp.i

CMakeFiles/snakeGame.dir/src/Snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snakeGame.dir/src/Snake.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kde/Desktop/lab/sfml/snakeGame/src/Snake.cpp -o CMakeFiles/snakeGame.dir/src/Snake.cpp.s

CMakeFiles/snakeGame.dir/src/Fruit.cpp.o: CMakeFiles/snakeGame.dir/flags.make
CMakeFiles/snakeGame.dir/src/Fruit.cpp.o: ../src/Fruit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kde/Desktop/lab/sfml/snakeGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/snakeGame.dir/src/Fruit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snakeGame.dir/src/Fruit.cpp.o -c /home/kde/Desktop/lab/sfml/snakeGame/src/Fruit.cpp

CMakeFiles/snakeGame.dir/src/Fruit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snakeGame.dir/src/Fruit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kde/Desktop/lab/sfml/snakeGame/src/Fruit.cpp > CMakeFiles/snakeGame.dir/src/Fruit.cpp.i

CMakeFiles/snakeGame.dir/src/Fruit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snakeGame.dir/src/Fruit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kde/Desktop/lab/sfml/snakeGame/src/Fruit.cpp -o CMakeFiles/snakeGame.dir/src/Fruit.cpp.s

CMakeFiles/snakeGame.dir/src/Point.cpp.o: CMakeFiles/snakeGame.dir/flags.make
CMakeFiles/snakeGame.dir/src/Point.cpp.o: ../src/Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kde/Desktop/lab/sfml/snakeGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/snakeGame.dir/src/Point.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snakeGame.dir/src/Point.cpp.o -c /home/kde/Desktop/lab/sfml/snakeGame/src/Point.cpp

CMakeFiles/snakeGame.dir/src/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snakeGame.dir/src/Point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kde/Desktop/lab/sfml/snakeGame/src/Point.cpp > CMakeFiles/snakeGame.dir/src/Point.cpp.i

CMakeFiles/snakeGame.dir/src/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snakeGame.dir/src/Point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kde/Desktop/lab/sfml/snakeGame/src/Point.cpp -o CMakeFiles/snakeGame.dir/src/Point.cpp.s

CMakeFiles/snakeGame.dir/src/Game.cpp.o: CMakeFiles/snakeGame.dir/flags.make
CMakeFiles/snakeGame.dir/src/Game.cpp.o: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kde/Desktop/lab/sfml/snakeGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/snakeGame.dir/src/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snakeGame.dir/src/Game.cpp.o -c /home/kde/Desktop/lab/sfml/snakeGame/src/Game.cpp

CMakeFiles/snakeGame.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snakeGame.dir/src/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kde/Desktop/lab/sfml/snakeGame/src/Game.cpp > CMakeFiles/snakeGame.dir/src/Game.cpp.i

CMakeFiles/snakeGame.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snakeGame.dir/src/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kde/Desktop/lab/sfml/snakeGame/src/Game.cpp -o CMakeFiles/snakeGame.dir/src/Game.cpp.s

# Object files for target snakeGame
snakeGame_OBJECTS = \
"CMakeFiles/snakeGame.dir/src/snakeGame.cpp.o" \
"CMakeFiles/snakeGame.dir/src/Snake.cpp.o" \
"CMakeFiles/snakeGame.dir/src/Fruit.cpp.o" \
"CMakeFiles/snakeGame.dir/src/Point.cpp.o" \
"CMakeFiles/snakeGame.dir/src/Game.cpp.o"

# External object files for target snakeGame
snakeGame_EXTERNAL_OBJECTS =

snakeGame: CMakeFiles/snakeGame.dir/src/snakeGame.cpp.o
snakeGame: CMakeFiles/snakeGame.dir/src/Snake.cpp.o
snakeGame: CMakeFiles/snakeGame.dir/src/Fruit.cpp.o
snakeGame: CMakeFiles/snakeGame.dir/src/Point.cpp.o
snakeGame: CMakeFiles/snakeGame.dir/src/Game.cpp.o
snakeGame: CMakeFiles/snakeGame.dir/build.make
snakeGame: /home/kde/lib/SFML-2.5.1/lib/libsfml-graphics-s.a
snakeGame: /home/kde/lib/SFML-2.5.1/lib/libsfml-audio-s.a
snakeGame: /home/kde/lib/SFML-2.5.1/lib/libsfml-window-s.a
snakeGame: /usr/lib/x86_64-linux-gnu/libudev.so
snakeGame: /usr/lib/x86_64-linux-gnu/libGL.so
snakeGame: /usr/lib/x86_64-linux-gnu/libGLU.so
snakeGame: /usr/lib/x86_64-linux-gnu/libOpenGL.so
snakeGame: /usr/lib/x86_64-linux-gnu/libX11.so
snakeGame: /usr/lib/x86_64-linux-gnu/libXrandr.so
snakeGame: /usr/lib/x86_64-linux-gnu/libX11.so
snakeGame: /usr/lib/x86_64-linux-gnu/libXrandr.so
snakeGame: /usr/lib/x86_64-linux-gnu/libfreetype.so
snakeGame: /usr/lib/x86_64-linux-gnu/libopenal.so
snakeGame: /home/kde/lib/SFML-2.5.1/lib/libsfml-system-s.a
snakeGame: /usr/lib/x86_64-linux-gnu/libvorbisenc.so
snakeGame: /usr/lib/x86_64-linux-gnu/libvorbisfile.so
snakeGame: /usr/lib/x86_64-linux-gnu/libvorbis.so
snakeGame: /usr/lib/x86_64-linux-gnu/libogg.so
snakeGame: /usr/lib/x86_64-linux-gnu/libvorbisenc.so
snakeGame: /usr/lib/x86_64-linux-gnu/libvorbisfile.so
snakeGame: /usr/lib/x86_64-linux-gnu/libvorbis.so
snakeGame: /usr/lib/x86_64-linux-gnu/libogg.so
snakeGame: /usr/lib/x86_64-linux-gnu/libFLAC.so
snakeGame: CMakeFiles/snakeGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kde/Desktop/lab/sfml/snakeGame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable snakeGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/snakeGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/snakeGame.dir/build: snakeGame

.PHONY : CMakeFiles/snakeGame.dir/build

CMakeFiles/snakeGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/snakeGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/snakeGame.dir/clean

CMakeFiles/snakeGame.dir/depend:
	cd /home/kde/Desktop/lab/sfml/snakeGame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kde/Desktop/lab/sfml/snakeGame /home/kde/Desktop/lab/sfml/snakeGame /home/kde/Desktop/lab/sfml/snakeGame/build /home/kde/Desktop/lab/sfml/snakeGame/build /home/kde/Desktop/lab/sfml/snakeGame/build/CMakeFiles/snakeGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/snakeGame.dir/depend

