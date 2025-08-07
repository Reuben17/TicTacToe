#include "Game.h"
#include <iostream>

int main(){
    std::string player1, player2;
    std::cout << "Enter Player 1 Name: ";
    std::getline(std::cin, player1);
    std::cout << "Enter Player 2 Name: ";
    std::getline(std::cin, player2);

    Game ttt(player1 ,player2);
    ttt.play();

    return 0;
    
}