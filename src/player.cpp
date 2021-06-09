#include "player.h"
#include <sstream>

Player::Player(){}

Player::Player(std::string name_)
    :name{name_}, score{0}
    {

    }

Player::Player(std::string name_, int score_)
    :name{name_}
    {
        SetScore(score_);
    }

int Player::GetScore(){return score;}
void Player::SetScore(int s){
    if(s>=0){ score = s;}
}

std::ostream& operator<<(std::ostream& os, const Player& P){
    std::stringstream ss{};
    ss << P.name << "\t" << P.score;
    os << ss.str();
    return os;
}