#include "menu.h"

constexpr std::size_t kFramesPerSecond{60};
constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
constexpr std::size_t kScreenWidth{640};
constexpr std::size_t kScreenHeight{640};
constexpr std::size_t kGridWidth{32};
constexpr std::size_t kGridHeight{32};

Menu::Menu()
    : path_to_high_scores{"high_scores.txt"},
      is_running{true}
{
    //renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight); 
    //reader.open(path_to_high_scores);
    LoadHighScores();
}

Menu::Menu(std::string path_to_high_scores_)
    : is_running(true)
{
    //renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    std::ifstream reader(path_to_high_scores_);
    if(!reader.is_open()){
        path_to_high_scores = "high_scores.txt";
        //reader.open(path_to_high_scores);
    }
    else{
        reader.close();
    }
    LoadHighScores();
}

void Menu::Display(){
    // Display NCurses window
    // For now use standard consol input
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
    //CommandInput(input);
    switch(input){
        case 'n' :
            std::cout<<"New Game!\n";
            break;
        case 's' :
            DisplayHighScores();
            break;
        case 'e' :
            std::cout<<"Exiting...";
            is_running = false;
            break;
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
                    //std::cout<<"Adding: "<<next<< " to name string\n";
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
}

void Menu::WriteHighScores(){
    // write the high scores to the file specified by path_to_high_scores
    std::cout << "Saving high scores to: " << path_to_high_scores <<"...\n";
    /*
    writer.open(path_to_high_scores);
    if(writer.is_open()){
        for(Player P : high_scores){
            writer << P << "\n";
        }
    }
    writer.close();
    */
}

bool Menu::CheckHighScores(int score_){
    std::cout<<"Check the high score list to see if the game score is higher than the lowest high score\n";
    return false;
}