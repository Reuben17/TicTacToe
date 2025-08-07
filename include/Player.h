#pragma once
#include <iostream>

class Player{

    public:
     Player(std::string playerName, char playerMark);
     std::string getName();
     char getMark();

     private:
     std::string name;
     char mark;
};