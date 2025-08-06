#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char currentMark;
int currentPlayer;


void displayBoard() {
    cout << "\n";

    for (int i =0; i < 3; i++) {
        cout << "\t\t\t";
        
        for (int j = 0; j < 3; j++) {
            cout <<" " <<  board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if ( i < 2) cout << "\t\t\t---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(){
    for (int i = 0; i < 3; i++){
        //rows and columns
        if ((board[i][0] == currentMark && board[i][1] == currentMark
            && board[i][2] == currentMark) || (board[0][i] == currentMark 
            && board[1][i] == currentMark && board[2][i] == currentMark))
            return true;
            }      

        //diagonals
        if ((board[0][0] == currentMark && board[1][1] == currentMark
            && board[2][2] == currentMark) || (board[0][2] == currentMark 
            && board[1][1] == currentMark && board[2][0] == currentMark))
            return true;
    
    return false;        
    }

bool checkDraw(){
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] !='X' && board[i][j] != 'O')
            return false;

    return true;
    }

void switchPlayer(){
    currentPlayer =(currentPlayer == 1) ? 2:1;
    currentMark = (currentPlayer == 1) ? 'X' : 'O';
}

void makeMove(){
    int move;
    cout << "Player " << currentPlayer << "(" << currentMark << "), enter position (1-9): ";
    cin >> move;

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (move < 1 || move >> 9 || board[row][col] == 'X' || board[row][col] == 'O'){
        cout << "Invalid move! Try again.\n";
        makeMove();
    } else {
        board[row][col] = currentMark;
    }
}

int main(){
    currentPlayer = 1;
    currentMark = 'X';

    while(true){
        displayBoard();
        makeMove();

        if (checkWin()){
            displayBoard();
            cout << "Player" << currentPlayer << "(" << currentMark << ") wins!\n";
            break;
        }

        if (checkDraw()){
            displayBoard();
            cout <<  "It's a draw!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}