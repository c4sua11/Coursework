#include "CheckersGame.h"

using namespace std;

CheckersGame::CheckersGame() {
    outFile.open("moves.txt"); // Открываем файл для записи
    if (!outFile) { // Проверяем, что файл успешно открыт
        std::cout << "Unable to open file";
        exit(1); // Завершаем программу с ошибкой
    }
}

CheckersGame::~CheckersGame() {
    outFile.close(); // Закрываем файл при завершении программы
}

void CheckersGame::start() {
    board.printBoard();

    char currentPlayer = 'o'; // Шашки первого игрока
    while (true) {
        // Определение текущего игрока
        cout << "Текущий игрок: " << (currentPlayer == 'o' ? "Чёрный" : "Белый") << endl;

        // Ввод хода игрока
        Move move = getPlayerMove(currentPlayer);

        // Проверка валидности хода
        if (board.isValidMove(move, currentPlayer)) {
            // Выполнение хода
            makeMove(move, currentPlayer);
            board.printBoard();
            // Смена игрока
            currentPlayer = (currentPlayer == 'o' ? 'x' : 'o');
        }
        else {
            cout << "Неверный ход. Попробуйте ещё раз." << endl;
        }
    }
}

Move CheckersGame::getPlayerMove(char playerPiece) const {
    char fromCol, toCol;
    int fromRow, toRow;

    cout << "Введите координаты (например, a3 b4): ";
    cin >> fromCol >> fromRow >> toCol >> toRow;

    return Move(8 - fromRow, fromCol - 'a', 8 - toRow, toCol - 'a');
}

void CheckersGame::makeMove(const Move& move, char playerPiece) {
    board.makeMove(move, playerPiece, outFile);
}
