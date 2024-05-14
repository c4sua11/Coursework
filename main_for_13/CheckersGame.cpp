#include "CheckersGame.h"

using namespace std;

CheckersGame::CheckersGame() {
    outFile.open("moves.txt"); // ��������� ���� ��� ������
    if (!outFile) { // ���������, ��� ���� ������� ������
        std::cout << "Unable to open file";
        exit(1); // ��������� ��������� � �������
    }
}

CheckersGame::~CheckersGame() {
    outFile.close(); // ��������� ���� ��� ���������� ���������
}

void CheckersGame::start() {
    board.printBoard();

    char currentPlayer = 'o'; // ����� ������� ������
    while (true) {
        // ����������� �������� ������
        cout << "������� �����: " << (currentPlayer == 'o' ? "׸����" : "�����") << endl;

        // ���� ���� ������
        Move move = getPlayerMove(currentPlayer);

        // �������� ���������� ����
        if (board.isValidMove(move, currentPlayer)) {
            // ���������� ����
            makeMove(move, currentPlayer);
            board.printBoard();
            // ����� ������
            currentPlayer = (currentPlayer == 'o' ? 'x' : 'o');
        }
        else {
            cout << "�������� ���. ���������� ��� ���." << endl;
        }
    }
}

Move CheckersGame::getPlayerMove(char playerPiece) const {
    char fromCol, toCol;
    int fromRow, toRow;

    cout << "������� ���������� (��������, a3 b4): ";
    cin >> fromCol >> fromRow >> toCol >> toRow;

    return Move(8 - fromRow, fromCol - 'a', 8 - toRow, toCol - 'a');
}

void CheckersGame::makeMove(const Move& move, char playerPiece) {
    board.makeMove(move, playerPiece, outFile);
}
