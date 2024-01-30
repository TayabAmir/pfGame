#include <iostream>
using namespace std;

const int gridSize = 3;
char board[gridSize][gridSize] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void assignValue(string ox, char Player);
bool checkRows(char symbol);
bool checkColumns(char symbol);
bool checkDiagonals(char symbol);
bool isWinner(char symbol);

void displayBoard() {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < gridSize; i++) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < gridSize; j++) {
            cout << "|" << board[i][j];
        }
        cout << "|" << endl;
    }
    cout << "  -------" << endl;
}

int main() {
    int counter = 1;
    string ox;
    char xPlayer = 'X', oPlayer = 'O';

    while (counter <= 5) {
        cout << "Current Board:\n";
        displayBoard();
        cout << "Player " << oPlayer << "'s Turn. Enter position (e.g., A0): ";
        cin >> ox;
        assignValue(ox, oPlayer);

        if (isWinner(oPlayer)) {
            cout << endl << endl << "Player " << oPlayer << " wins!\n";
            displayBoard();
            break;
        }

        if (counter == 5) {
            cout << "It's a draw!\n";
            break;
        }

        cout << "Current Board:\n";
        displayBoard();
        
        cout << "Player " << xPlayer << "'s Turn. Enter position (e.g., B1): ";
        cin >> ox;
        assignValue(ox, xPlayer);

        if (isWinner(xPlayer)) {
            cout << endl << endl << "Player " << xPlayer << " wins!\n";
            displayBoard();
            break;
        }

        counter++;
    }

    return 0;
}

void assignValue(string ox, char Player) {
    int row = ox[0] - 'A';
    int col = ox[1] - '0';
    board[row][col] = Player;
}

bool checkRows(char symbol) {
    for (int row = 0; row < gridSize; row++) {
        int count = 0;
        for (int col = 0; col < gridSize; col++) {
            if (board[row][col] == symbol) {
                count++;
            }
        }
        if (count == gridSize) {
            return true;
        }
    }
    return false;
}

bool checkColumns(char symbol) {
    for (int col = 0; col < gridSize; col++) {
        int count = 0;
        for (int row = 0; row < gridSize; row++) {
            if (board[row][col] == symbol) {
                count++;
            }
        }
        if (count == gridSize){
            return true;
        }
    }
    return false;
}

bool checkDiagonals(char symbol){
    int count = 0;
    for (int idx = 0; idx < gridSize; idx++) {
        if (board[idx][idx] == symbol) {
            count++;
        }
    }
    if (count == gridSize) {
        return true;
    }

    count = 0;
    int col=2;
    for (int row = 0; row < gridSize; row++) {
        if (board[row][col] == symbol) {
            count++;
        }
        col--;
    }
    if (count == gridSize) {
        return true;
    }
    
    return false;
}

bool isWinner(char symbol) {
    return checkRows(symbol) || checkColumns(symbol) || checkDiagonals(symbol);
}

