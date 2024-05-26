// include/Board.h
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
    void printBoard();
private:
    std::vector<std::vector<std::unique_ptr<Piece>>> board;
};

#endif // BOARD_H