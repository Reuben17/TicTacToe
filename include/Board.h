#pragma once

#include <vector>

class Board{

    public:
        Board();
        void display();
        bool update(int position, char mark);
        bool isWin(char mark);
        bool isDraw();
        void reset();

    private:
        std::vector<std::vector<char>> grid;
};
