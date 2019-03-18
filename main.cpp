#include <iostream>

using namespace std;

bool isWon(char, char[][3]);

bool isDraw(char[][3]);

void displayBoard(char[][3]);

void makeAMove(char[][3], char);

int main() {
    //
    //	PLEASE DO NOT CHANGE function main
    //
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);

    while (true) {
        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);
        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }

        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);

        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }

    return 0;
}




bool isWon(char c, char board[][3]) {
    for (int i = 0; i <= 2; i++) {
        if ((board[i][0] == c && board[i][1] == c && board[i][2] == c)
            ||
            (board[0][i] == c && board[1][i] == c && board[2][i] == c))
            return true;
    }
    return (board[0][0] == c && board[1][1] == c && board[2][2] == c)
           ||
           (board[0][2] == c && board[1][1] == c && board[2][0] == c);
}


void displayBoard(char board[3][3]) {


    int rowMax = 3, columnMax = 3;

    for (int row = 0; row < rowMax; row++) {
        cout << "-------------" << endl;
        for (int column = 0; column < columnMax; column++) {
            cout << board[row][column] << " | ";
        }
        cout << endl;

    }

    cout << "-------------" << endl;
}

void makeAMove(char board[3][3], char c) {

    int ROW = 3;
    int COL = 3;
    do {
        cout << "Enter a row(0,1,2) for player " << c << ":";
        cin >> ROW;
        cout << "Enter a column (0,1,2) for player " << c << ":";
        cin >> COL;
        if (board[ROW][COL] == ' ') {
            board[ROW][COL] = c;


        } else {
            if (ROW < 0 || ROW > 2 || COL < 0 || COL > 2) {
                cout << "Choose either 0,1,2 only" << endl;
            } else
                cout << "This cell is already occupied. Try a different cell" << endl;
            makeAMove(board, c);
        }


        cout << endl;


    } while (board[ROW][COL] == '*');

}

bool isDraw(char board[][3]) {

    int check = 0;
    for (int n = 0; n < 3; n++) {
        for (int i = 0; i < 3; i++) {
            if (board[n][i] == 'X' || board[n][i] == 'O')
                check++;
        }
    }
    if (check != 9)
        return false;
    if (!isWon('X', board) && !isWon('O', board))
        return true;

}




