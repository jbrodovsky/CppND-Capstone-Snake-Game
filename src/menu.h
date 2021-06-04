#ifndef MENU_H
#define MENU_H

#include <algorithm>
#include <iostream>
//#include <ncurses.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
//#include "controller.h"
//#include "game.h"
//#include "renderer.h"
#include "player.h"
//#include "SDL.h"

class Menu{
public:
    Menu();     // Default Constructor, initializes path_to_high_scores to './high_scores.txt'
    Menu(std::string path_to_high_scores_); // Initializes path_to_high_scores to the specified filepath

    void Display();         // Displays the main menu
    void DisplayHighScores(); // Displays the high score list
    void StartGame();       // Start a new game
    void LoadHighScores();  // Loads the high score list
    void WriteHighScores(); // Saves the high score list
    bool CheckHighScores(int score_);   // Checks to see if current game's score meets minimum high score list
    void WaitForInput();
    void CommandInput(char c_); // Takes user input

    bool is_running;

private:
    //std::ifstream reader;
    //std::ofstream writer;
    std::string path_to_high_scores;
    std::vector<Player> high_scores;
    //Game my_game;
    //Renderer Renderer;
    //Controller controller;
    
};

#endif