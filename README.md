# CPPND: Capstone Snake Game Example

This is my Capstone project for the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses. In this project, I extended the Snake game, following the principles I learned throughout this Nanodegree Program.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

# My Project: Snake++

## General Description

For this project I wanted to add in a menu interface for running multiple games and storing a list of high scores in the manner of a classic arcade game. This required the creation of a user interface Menu class, as well as a small Player class to allow for easy data recording and managament. The program stores the high score list as a vector of players in memory and writes that list to a text file for long term storage. At start up, the high score list is loaded from storage and displayed. The user may then either display the high score list, start a new game, or exit the program using console input.

## Class Descriptions

### Menu

Menu is the new user interface for the program. It handles all the user I/O, file I/O, and running the actual Snake++ game. After a game is played it checks to see if the current game score is higher than the lowest score on the high scores list. If so, it asks for the player's name and appends a new Player to the high scores list. The list is then sorted and only the top ten scores are written to storage.

### Player

Player is a class used to facilitate manipulating the data on the high scores list more easily. It has two member variables: a string name and an int score as well as some associated constructors, getters, and setters. Notably, it overloads the << opperator to facilitate displaying the high scores list to the console.

## Rubric points 

### Loops, Functions, I/O

1. The project demonstrates an understanding of C++ functions and control structures.
2. The project reads data from a file and process the data, or the program writes data to a file.
3. The project accepts user input and processes the input.

### Object Oriented Programming

1. The project uses Object Oriented Programming Techniques.
2. Classes use appropriate access specifiers for class members.
3. Class constructors utilize member initialization lists.
4. Classes abstract implementation details from their interfaces.
5. Classes encapsulate behavior.
6. 