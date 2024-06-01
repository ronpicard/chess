#ifndef MOVE_H
#define MOVE_H

#include "Board.h"

class Move {
public:
    Move(Board& board);
    bool makeMove(int startX, int startY, int endX, int endY);
    Board& board;
    
private:


    bool isLegalMove(int startX, int startY, int endX, int endY) const;
    bool isPathClear(int startX, int startY, int endX, int endY) const;

    bool isLegalPawnMove(int startX, int startY, int endX, int endY) const;
    bool isLegalKnightMove(int startX, int startY, int endX, int endY) const;
    bool isLegalBishopMove(int startX, int startY, int endX, int endY) const;
    bool isLegalRookMove(int startX, int startY, int endX, int endY) const;
    bool isLegalQueenMove(int startX, int startY, int endX, int endY) const;
    bool isLegalKingMove(int startX, int startY, int endX, int endY) const;
};

#endif // MOVE_H
