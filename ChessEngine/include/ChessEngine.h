#ifndef CHESSENGINE_H
#define CHESSENGINE_H

#include "Board.h"
#include "Evaluator.h"
#include "Solver.h"
#include <tuple>

class ChessEngine {
public:
    ChessEngine();
    void start();
    void movePiece(int startX, int startY, int endX, int endY);
    void printBoard() const;
    std::tuple<int, int, int, int> findBestMove(int depth);
    int evaluateBoard() const;

private:
    Board board;
    Evaluator evaluator;
    Solver solver;
    bool currentTurn; // true for white, false for black
};

#endif // CHESSENGINE_H
