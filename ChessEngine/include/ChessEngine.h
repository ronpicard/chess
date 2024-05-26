#ifndef CHESSENGINE_H
#define CHESSENGINE_H

#include "Board.h"
#include "Solver.h"
#include "Evaluator.h"
#include <unordered_map>
#include <string>
#include <tuple>

class ChessEngine {
public:
    ChessEngine();
    void start();
    bool movePiece(int startX, int startY, int endX, int endY);
    void printBoard() const;
    std::tuple<int, int, int, int> findBestMove(int depth);
    int evaluateBoard() const;
    bool isCheckmate() const;
    bool isStalemate() const;
    bool checkDrawByRepetition() const;
    bool isWhiteTurn() const;
    void printAllLegalMoves() const;  // Declaration for printing legal moves for both players

private:
    Board board;
    Solver solver;
    Evaluator evaluator;
    bool currentTurn;
    std::unordered_map<std::string, int> boardStateCount;
    void trackBoardState();
    void printLegalMoves(bool isWhite) const;  // Adjusted to take a boolean argument
};

#endif // CHESSENGINE_H
