#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
public:
    Player();
    Player(std::string name_);
    Player(std::string name_, int score_);
    int GetScore();
    void SetScore(int s);
    friend std::ostream& operator<<(std::ostream& os, const Player& P);
    std::string name;
    
private:
    int score;

};

#endif