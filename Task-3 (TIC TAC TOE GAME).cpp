#include <iostream>
#include <vector>
 
using namespace std;

void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}
 
char checkWinner(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return ' '; // If no winner
}
 
bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
 
int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize empty board
    char currentPlayer = 'X'; // Player X starts the game
 
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player X goes first." << endl;
 
    while (true) {
        // Display current state of the board
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }
 
        board[row - 1][col - 1] = currentPlayer;
 
        char winner = checkWinner(board);
        if (winner != ' ') {
            displayBoard(board);
            cout << "Player " << winner << " wins!" << endl;
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
 
    cout << "Thanks for playing!" << endl;
 
    return 0;
}



