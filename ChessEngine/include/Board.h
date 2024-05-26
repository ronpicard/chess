#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>
#include <memory>

class Board {
public:
    Board();
    void initialize();
    bool movePiece(int startX, int startY, int endX, int endY);
    bool isMoveLegal(int startX, int startY, int endX, int endY) const;
    void printBoard() const;
    Board clone() const;
    Piece* getPiece(int x, int y) const;

private:
    std::vector<std::vector<std::unique_ptr<Piece>>> board;
    bool isPathClear(int startX, int startY, int endX, int endY) const;
    bool isPawnMoveLegal(int startX, int startY, int endX, int endY) const;
    bool isRookMoveLegal(int startX, int startY, int endX, int endY) const;
    bool isKnightMoveLegal(int startX, int startY, int endX, int endY) const;
    bool isBishopMoveLegal(int startX, int startY, int endX, int endY) const;
    bool isQueenMoveLegal(int startX, int startY, int endX, int endY) const;
    bool isKingMoveLegal(int startX, int startY, int endX, int endY) const;
};

#endif // BOARD_H
