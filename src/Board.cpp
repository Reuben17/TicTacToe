#include "Board.h"
#include <iostream>

Board::Board(){
    grid =
    {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
}

void Board::display(){
    std::cout << "\n";

    for (int i = 0; i < 3; ++i) {
        std::cout << "\t\t\t";
        for (int j = 0; j < 3; ++j) {
            std::cout << grid[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "\t\t\t---+---+---\n";
    }
    std::cout << "\n";
}

bool Board::update(int position, char mark){
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (position < 1 || position > 9 || grid[row][col] == 'X' || grid[row][col] == 'O')
        return false;

    grid[row][col] = mark;
    return true;
}

bool Board::isWin(char mark){
    for (int i = 0; i < 3; ++i) {
        if ((grid[i][0] == mark && grid[i][1] == mark && grid[i][2] == mark) ||
            (grid[0][i] == mark && grid[1][i] == mark && grid[2][i] == mark))
            return true;
    }
    return (grid[0][0] == mark && grid[1][1] == mark && grid[2][2] == mark) ||
           (grid[0][2] == mark && grid[1][1] == mark && grid[2][0] == mark);

}

bool Board::isDraw(){
    for (auto& row : grid)
        for (char cell : row)
            if (cell != 'X' && cell != 'O')
                return false;
    return true;
}

void Board::reset() {
    char val = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            grid[i][j] = val++;
}