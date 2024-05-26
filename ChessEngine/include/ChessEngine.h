#ifndef CHESSENGINE_H
#define CHESSENGINE_H

#include "Board.h"
#include "Evaluator.h"
#include "Solver.h"
#include <tuple>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

class ChessEngine {
public:
    ChessEngine();
    void start();
    bool movePiece(int startX, int startY, int endX, int endY);
    void printBoard() const;
    std::tuple<int, int, int, int> findBestMove(int depth);
    int evaluateBoard() const;
    void printLegalMoves() const;
    bool checkDrawByRepetition() const;
    bool isCheckmate() const;
    bool isStalemate() const;
    bool isWhiteTurn() const; // Added this method

private:
    Board board;
    Evaluator evaluator;
    Solver solver;
    bool currentTurn; // true for white, false for black
    std::unordered_map<std::string, int> boardStateCount;

    void trackBoardState();
};

#endif // CHESSENGINE_H
