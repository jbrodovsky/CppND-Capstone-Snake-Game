#include "menu.h"
#include "controller.h"
#include "game.h"
#include "renderer.h"

constexpr std::size_t kFramesPerSecond{60};
constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
constexpr std::size_t kScreenWidth{640};
constexpr std::size_t kScreenHeight{640};
constexpr std::size_t kGridWidth{32};
constexpr std::size_t kGridHeight{32};

Menu::Menu(std::string path_to_high_scores_)
    : is_running(true), path_to_high_scores(path_to_high_scores_)
{   
    LoadHighScores();
}

void Menu::Display(){
    std::cout<<"Hello and welcome to SNAKE++!\n";
    Menu::DisplayHighScores();
    std::cout << "----------------------------------------------\n";
}

void Menu::DisplayHighScores(){
    int rank = 1;
    std::cout << "HIGH SCORE LIST:\n";
    for(Player p : high_scores){
        std::cout << rank <<": " << p <<"\n";
        rank++;
    }
}

void Menu::WaitForInput(){
    char input;
    std::cout << "\n\nPress a key to continue:\n\t(n) to start a new game\n\t(s) to show the high scores list\n\t(e) to exit.\n";
    std::cin >> input;
    switch(input){
        case 'n' :
            std::cout<<"New Game!\n";
            RunGame();
            sort(high_scores.begin(), high_scores.end(), [](Player& A, Player& B){ return (B.GetScore() < A.GetScore());});
            high_scores.pop_back();
            WriteHighScores();
            break;
        case 's' :
            DisplayHighScores();
            break;
        case 'e' :
            std::cout<<"Exiting...";
            is_running = false;
            break;
        default : 
            std::cout<<"Input not recognizied.\n";

    }
}

void Menu::LoadHighScores(){
    // Load high scores list and build high score vector
    std::cout << "Loading high scores from: " << path_to_high_scores <<" ...\n";
    std::ifstream reader(path_to_high_scores);
    std::string line;
    if(reader.is_open()){
        while(std::getline(reader, line)){
            std::replace(line.begin(), line.end(), ',', '|');
            std::stringstream linestream(line);
            int score;
            std::string name, next;
            while((linestream >> next)){
                if(next !="|"){
                    name += next;
                    name += " ";
                }
                else{
                    break;
                }
            }
            linestream >> score;
            Player P(name, score);
            high_scores.push_back(P);
            if(reader.eof()){
                break;
            }
        }
    }
    else{
        path_to_high_scores = "high_scores.txt";
        std::cout << "High score list does not exist. Will save any new high scores to the default location: " << path_to_high_scores << "\n";
    }
    reader.close();
    sort(high_scores.begin(), high_scores.end(), [](Player& A, Player& B){ return (B.GetScore() < A.GetScore());});
}

void Menu::WriteHighScores(){
    // write the high scores to the file specified by path_to_high_scores
    std::cout << "Saving high scores to: " << path_to_high_scores <<"...\n";
    std::ofstream writer(path_to_high_scores);
    if(writer.is_open()){
        for(Player P : high_scores){
            writer << P.name << " | " << P.GetScore()<< "\n";
        }
    }
    writer.close();
}

void Menu::RunGame(){
    Controller controller;
    Game my_game(kGridWidth, kGridHeight);
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Player lowscorer;
    
    if(high_scores.size()>=1){
        lowscorer = high_scores[high_scores.size()-1];
    }
    else {
        lowscorer.name = "Low Score";
        lowscorer.SetScore(1);
    }
    std::cout << "Marker...\n";
        
    my_game.Run(controller, renderer, kMsPerFrame);
    if(lowscorer.GetScore() < my_game.GetScore() || high_scores.size() < 10){
        std::cout<<"High score achieved!\nEnter your name:\t";
        Player highscorer;
        std::cin >> highscorer.name;
        highscorer.SetScore(my_game.GetScore());
        high_scores.push_back(highscorer);
    }
}