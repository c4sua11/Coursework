#pragma once
#ifndef MOVE_H
#define MOVE_H

class Move {
public:
    int fromRow, fromCol;
    int toRow, toCol;

    Move(int fromR, int fromC, int toR, int toC);
};

#endif // MOVE_H
