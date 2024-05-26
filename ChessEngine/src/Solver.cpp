#include "Solver.h"
#include <limits>
#include <cctype>

Solver::Solver(const Evaluator& evaluator) : evaluator(evaluator) {}

std::tuple<int, int, int, int> Solver::findBestMove(Board& board, int depth, bool isWhiteTurn, const std::unordered_set<std::string>& statesToAvoid) {
    int bestScore = isWhiteTurn ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
    std::tuple<int, int, int, int> bestMove = {-1, -1, -1, -1};
    
    for (const auto& move : generateLegalMoves(board, isWhiteTurn)) {
        Board newBoard = board.clone();
        newBoard.movePiece(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move));
        std::string newStateHash = newBoard.getBoardStateHash();
        if (statesToAvoid.find(newStateHash) != statesToAvoid.end()) {
            continue; // Skip moves leading to repeated board states
        }
        if (newBoard.isInCheck(isWhiteTurn)) {
            continue; // Skip moves that leave the king in check
        }
        int score = minimax(newBoard, depth - 1, !isWhiteTurn, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), statesToAvoid);
        if ((isWhiteTurn && score > bestScore) || (!isWhiteTurn && score < bestScore)) {
            bestScore = score;
            bestMove = move;
        }
    }
    return bestMove;
}

int Solver::minimax(Board& board, int depth, bool isMaximizingPlayer, int alpha, int beta, const std::unordered_set<std::string>& statesToAvoid) {
    if (depth == 0) {
        return evaluator.evaluate(board);
    }

    std::string boardStateHash = board.getBoardStateHash();
    if (statesToAvoid.find(boardStateHash) != statesToAvoid.end()) {
        return isMaximizingPlayer ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
    }

    bool isWhite = isMaximizingPlayer;
    if (board.isInCheck(isWhite) && !board.hasLegalMoves(isWhite)) {
        return isMaximizingPlayer ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
    }

    if (isMaximizingPlayer) {
        int maxEval = std::numeric_limits<int>::min();
        for (const auto& move : generateLegalMoves(board, true)) {
            Board newBoard = board.clone();
            newBoard.movePiece(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move));
            if (newBoard.isInCheck(true)) {
                continue; // Skip moves that leave the king in check
            }
            int eval = minimax(newBoard, depth - 1, false, alpha, beta, statesToAvoid);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {
                break;
            }
        }
        return maxEval;
    } else {
        int minEval = std::numeric_limits<int>::max();
        for (const auto& move : generateLegalMoves(board, false)) {
            Board newBoard = board.clone();
            newBoard.movePiece(std::get<0>(move), std::get<1>(move), std::get<2>(move), std::get<3>(move));
            if (newBoard.isInCheck(false)) {
                continue; // Skip moves that leave the king in check
            }
            int eval = minimax(newBoard, depth - 1, true, alpha, beta, statesToAvoid);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) {
                break;
            }
        }
        return minEval;
    }
}

std::vector<std::tuple<int, int, int, int>> Solver::generateLegalMoves(const Board& board, bool isMaximizingPlayer) const {
    std::vector<std::tuple<int, int, int, int>> moves;
    for (int startX = 0; startX < 8; ++startX) {
        for (int startY = 0; startY < 8; ++startY) {
            if (board.getPiece(startX, startY) != nullptr) {
                char symbol = board.getPiece(startX, startY)->getSymbol();
                if ((isMaximizingPlayer && isupper(symbol)) || (!isMaximizingPlayer && islower(symbol))) {
                    for (int endX = 0; endX < 8; ++endX) {
                        for (int endY = 0; endY < 8; ++endY) {
                            if (board.isMoveLegal(startX, startY, endX, endY)) {
                                moves.emplace_back(startX, startY, endX, endY);
                            }
                        }
                    }
                }
            }
        }
    }
    return moves;
}
