#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include "Board.h"

struct MoveData {
    int startX, startY;
    int endX, endY;
};

class Move {
public:
    Move(Board& board);
    bool makeMove(int startX, int startY, int endX, int endY);
    std::vector<MoveData> getAllValidMoves(Color color) const;

private:
    Board& board;

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
