#include "ChessEngine.h"
#include <iostream>

ChessEngine::ChessEngine() : solver(evaluator), currentTurn(true) {
    board.initialize();
}

void ChessEngine::start() {
    std::cout << "Chess Engine Started!" << std::endl;
    printBoard();
}

bool ChessEngine::movePiece(int startX, int startY, int endX, int endY) {
    if (board.movePiece(startX, startY, endX, endY)) {
        std::cout << "Move successful!" << std::endl;
        currentTurn = !currentTurn; // Alternate turn
        return true;
    } else {
        std::cout << "Move failed!" << std::endl;
        return false;
    }
}

void ChessEngine::printBoard() const {
    board.printBoard();
}

std::tuple<int, int, int, int> ChessEngine::findBestMove(int depth) {
    printLegalMoves(); // Print legal moves before finding the best move
    return solver.findBestMove(board, depth, currentTurn);
}

int ChessEngine::evaluateBoard() const {
    return evaluator.evaluate(board);
}

void ChessEngine::printLegalMoves() const {
    auto legalMoves = solver.generateLegalMoves(board, currentTurn);
    std::cout << "Legal moves for " << (currentTurn ? "white" : "black") << ":" << std::endl;
    for (const auto& move : legalMoves) {
        std::cout << "(" << std::get<0>(move) << ", " << std::get<1>(move) << ") -> ("
                  << std::get<2>(move) << ", " << std::get<3>(move) << ")" << std::endl;
    }
}
