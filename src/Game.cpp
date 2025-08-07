#include "Game.h"
#include <chrono>
#include <thread>

Game::Game(std::string name1, std::string name2)
    :player1(name1,'X'),player2(name2, 'O'){
        currentPlayer = &player1;
};

void Game::switchTurn(){
        currentPlayer = (currentPlayer == &player1) ? &player2: &player1;
}

void Game::play(){
    while (true){
        board.display();
        int move;

        std::cout << currentPlayer->getName() << " (" << currentPlayer->getMark() << "), enter position (1-9): ";
        std::cin >> move;

        if (!board.update(move, currentPlayer->getMark())) {
            std::cout << "Invalid move! Try again.\n";
            continue;
        }

        if (board.isWin(currentPlayer->getMark())) {
            board.display();
            std::cout << currentPlayer->getName() << " wins! The game will restart in 5 seconds.\n";
            std::this_thread::sleep_for(std::chrono::seconds(5));
            board.reset();
        }

        if (board.isDraw()) {
            board.display();
            std::cout << "It's a draw! The game will restart in 5 seconds.\n";
            std::this_thread::sleep_for(std::chrono::seconds(5));
            board.reset();
        }

        switchTurn();
    }
    
}

