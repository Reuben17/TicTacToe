#pragma once

#include "Board.h"
#include "Player.h"
#include <iostream>

class Game{
    public:
        Game(std::string name1, std::string name2);
        void switchTurn();
        void play();

    private:
        Board board;
        Player player1;
        Player player2;
        Player* currentPlayer;

};
