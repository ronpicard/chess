#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Board.h"
#include "Move.h"

class AIPlayer {
public:
    AIPlayer(Board& board, Move& move, int depth);
    MoveData getBestMove(Color color);

private:
    Board& board;
    Move& move;
    int depth;

    int minimax(int depth, Color color, bool isMaximizingPlayer);
    int evaluateBoard() const;
};

#endif // AIPLAYER_H
