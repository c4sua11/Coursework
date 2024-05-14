#pragma once
#ifndef CHECKERSGAME_H
#define CHECKERSGAME_H

#include <fstream>
#include "CheckersBoard.h"
#include "Move.h"

class CheckersGame {
private:
    CheckersBoard board;
    std::ofstream outFile; // Объект для записи в файл

public:
    CheckersGame();
    ~CheckersGame();

    void start();
    Move getPlayerMove(char playerPiece) const;
    void makeMove(const Move& move, char playerPiece);
};

#endif // CHECKERSGAME_H
