#include "Player.h"

Player::Player(std::string playerName, char playerMark)
    :name(playerName),mark(playerMark){};

std::string Player::getName(){
    return name;
}

char Player::getMark(){
    return mark;
}