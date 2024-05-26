#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"
#include "Evaluator.h"
#include <tuple>
#include <vector>
#include <unordered_set>
#include <string>

class Solver {
public:
    Solver(const Evaluator& evaluator);
    std::tuple<int, int, int, int> findBestMove(Board& board, int depth, bool isWhiteTurn, const std::unordered_set<std::string>& statesToAvoid);
    std::vector<std::tuple<int, int, int, int>> generateLegalMoves(const Board& board, bool isMaximizingPlayer) const;

private:
    int minimax(Board& board, int depth, bool isMaximizingPlayer, int alpha, int beta, const std::unordered_set<std::string>& statesToAvoid);
    const Evaluator& evaluator;
};

#endif // SOLVER_H
