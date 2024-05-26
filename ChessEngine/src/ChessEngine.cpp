// src/ChessEngine.cpp
#include "ChessEngine.h"
#include <iostream>

ChessEngine::ChessEngine() {
    board.initialize();
}

void ChessEngine::start() {
    std::cout << "Chess Engine Started!" << std::endl;
    printBoard();
}

void ChessEngine::movePiece(int startX, int startY, int endX, int endY) {
    if (board.movePiece(startX, startY, endX, endY)) {
        std::cout << "Move successful!" << std::endl;
    } else {
        std::cout << "Move failed!" << std::endl;
    }
    printBoard();
}

void ChessEngine::printBoard() {
    board.printBoard();
}
