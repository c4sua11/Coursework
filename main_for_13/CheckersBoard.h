#pragma once
#ifndef CHECKERSBOARD_H
#define CHECKERSBOARD_H

#include <vector>
#include <fstream>
#include <iostream>
#include "Move.h"

class CheckersBoard {
private:
    std::vector<std::vector<char>> board;

public:
    static const int SIZE = 8;

    CheckersBoard();

    void initialize();
    void printBoard();
    bool isValidMove(const Move& move, char playerPiece) const;
    void makeMove(const Move& move, char playerPiece, std::ofstream& outFile);
};

#endif // CHECKERSBOARD_H
