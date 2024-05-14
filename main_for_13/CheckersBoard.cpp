#include "CheckersBoard.h"

using namespace std;

CheckersBoard::CheckersBoard() {
    initialize();
}

void CheckersBoard::initialize() {
    board = {
        {' ', 'o', ' ', 'o', ' ', 'o', ' ', 'o'},
        {'o', ' ', 'o', ' ', 'o', ' ', 'o', ' '},
        {' ', 'o', ' ', 'o', ' ', 'o', ' ', 'o'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'x', ' ', 'x', ' ', 'x', ' ', 'x', ' '},
        {' ', 'x', ' ', 'x', ' ', 'x', ' ', 'x'},
        {'x', ' ', 'x', ' ', 'x', ' ', 'x', ' '}
    };
}

void CheckersBoard::printBoard() {
    cout << "  a b c d e f g h" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << 8 - i << " ";
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << 8 - i << endl;
    }
    cout << "  a b c d e f g h" << endl;
}

bool CheckersBoard::isValidMove(const Move& move, char playerPiece) const {
    int fromRow = move.fromRow;
    int fromCol = move.fromCol;
    int toRow = move.toRow;
    int toCol = move.toCol;

    // Проверка, что начальная и конечная клетки находятся на доске
    if (fromRow < 0 || fromRow >= SIZE || fromCol < 0 || fromCol >= SIZE ||
        toRow < 0 || toRow >= SIZE || toCol < 0 || toCol >= SIZE) {
        return false;
    }

    // Проверка, что конечная клетка пуста
    if (board[toRow][toCol] != ' ') {
        return false;
    }

    // Проверка возможности движения на диагональ
    if (abs(toRow - fromRow) == 1 && abs(toCol - fromCol) == 1) {
        return true;
    }

    // Проверка возможности съесть шашку
    if (abs(toRow - fromRow) == 2 && abs(toCol - fromCol) == 2) {
        int midRow = (fromRow + toRow) / 2;
        int midCol = (fromCol + toCol) / 2;
        if (board[midRow][midCol] != ' ' && board[midRow][midCol] != playerPiece) {
            return true;
        }
    }
}

void CheckersBoard::makeMove(const Move& move, char playerPiece, std::ofstream& outFile) {
    int fromRow = move.fromRow;
    int fromCol = move.fromCol;
    int toRow = move.toRow;
    int toCol = move.toCol;

    // Перемещение шашки
    board[toRow][toCol] = playerPiece;
    board[fromRow][fromCol] = ' ';

    // Удаление съеденной шашки
    if (abs(toRow - fromRow) == 2 && abs(toCol - fromCol) == 2) {
        int midRow = (fromRow + toRow) / 2;
        int midCol = (fromCol + toCol) / 2;
        board[midRow][midCol] = ' ';
    }

    // Записываем ход в файл
    outFile << (playerPiece == 'o' ? "Чёрный" : "Белый") << ": "
        << char(move.fromCol + 'a') << 8 - move.fromRow << " -> "
        << char(move.toCol + 'a') << 8 - move.toRow << endl;
}

