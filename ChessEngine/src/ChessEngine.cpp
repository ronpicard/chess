#include "ChessEngine.h"
#include <iostream>

ChessEngine::ChessEngine() : solver(evaluator), currentTurn(true) {
    board.initialize();
}

void ChessEngine::start() {
    std::cout << "Chess Engine Started!" << std::endl;
    printBoard();
}

void ChessEngine::movePiece(int startX, int startY, int endX, int endY) {
    if (board.movePiece(startX, startY, endX, endY)) {
        std::cout << "Move successful!" << std::endl;
        currentTurn = !currentTurn; // Alternate turn
    } else {
        std::cout << "Move failed!" << std::endl;
    }
    printBoard();
}

void ChessEngine::printBoard() const {
    board.printBoard();
}

std::tuple<int, int, int, int> ChessEngine::findBestMove(int depth) {
    return solver.findBestMove(board, depth, currentTurn);
}

int ChessEngine::evaluateBoard() const {
    return evaluator.evaluate(board);
}
