// include/ChessEngine.h
#ifndef CHESSENGINE_H
#define CHESSENGINE_H

#include "Board.h"

class ChessEngine {
public:
    ChessEngine();
    void start();
    void movePiece(int startX, int startY, int endX, int endY);
    void printBoard();
private:
    Board board;
};

#endif // CHESSENGINE_H