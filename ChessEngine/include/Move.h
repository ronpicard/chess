#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include <unordered_map>
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
    bool isKingInCheck(Color color) const;
    bool isCheckmate(Color color) const;
    bool isStalemate(Color color) const;
    bool isInsufficientMaterial() const;
    bool isThreefoldRepetition() const;

private:
    Board& board;
    std::unordered_map<size_t, int> boardStateCounts;

    bool isLegalMove(int startX, int startY, int endX, int endY) const;
    bool isPathClear(int startX, int startY, int endX, int endY) const;
    bool moveResolvesCheck(const MoveData& move, Color color) const;
    size_t getBoardHash() const;

    bool isLegalPawnMove(int startX, int startY, int endX, int endY) const;
    bool isLegalKnightMove(int startX, int startY, int endX, int endY) const;
    bool isLegalBishopMove(int startX, int startY, int endX, int endY) const;
    bool isLegalRookMove(int startX, int startY, int endX, int endY) const;
    bool isLegalQueenMove(int startX, int startY, int endX, int endY) const;
    bool isLegalKingMove(int startX, int startY, int endX, int endY) const;
};

#endif // MOVE_H
