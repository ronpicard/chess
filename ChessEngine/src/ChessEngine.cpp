#include "ChessEngine.h"
#include <iostream>

ChessEngine::ChessEngine() : solver(evaluator), currentTurn(true) {
    board.initialize();
    trackBoardState(); // Track the initial board state
}

void ChessEngine::start() {
    std::cout << "Chess Engine Started!" << std::endl;
    printBoard();
    printAllLegalMoves(); // Print all legal moves at the start
}

bool ChessEngine::movePiece(int startX, int startY, int endX, int endY) {
    if (board.movePiece(startX, startY, endX, endY)) {
        std::cout << "Move successful!" << std::endl;
        currentTurn = !currentTurn; // Alternate turn
        trackBoardState();
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
    printLegalMoves(currentTurn); // Print legal moves before finding the best move
    std::unordered_set<std::string> statesToAvoid;
    for (const auto& entry : boardStateCount) {
        if (entry.second >= 2) {
            statesToAvoid.insert(entry.first);
        }
    }
    return solver.findBestMove(board, depth, currentTurn, statesToAvoid);
}

int ChessEngine::evaluateBoard() const {
    return evaluator.evaluate(board);
}

void ChessEngine::printLegalMoves(bool isWhite) const {
    auto legalMoves = solver.generateLegalMoves(board, isWhite);
    std::cout << "Legal moves for " << (isWhite ? "white" : "black") << ":" << std::endl;
    for (const auto& move : legalMoves) {
        std::cout << "(" << std::get<0>(move) << ", " << std::get<1>(move) << ") -> ("
                  << std::get<2>(move) << ", " << std::get<3>(move) << ")" << std::endl;
    }
}

void ChessEngine::printAllLegalMoves() const {
    std::cout << "Printing all legal moves at the start of the game." << std::endl;
    printLegalMoves(true);  // Print legal moves for white
    printLegalMoves(false); // Print legal moves for black
}

void ChessEngine::trackBoardState() {
    std::string stateHash = board.getBoardStateHash();
    if (boardStateCount.find(stateHash) == boardStateCount.end()) {
        boardStateCount[stateHash] = 1;
    } else {
        boardStateCount[stateHash]++;
    }
}

bool ChessEngine::checkDrawByRepetition() const {
    for (const auto& entry : boardStateCount) {
        if (entry.second >= 3) {
            return true;
        }
    }
    return false;
}

bool ChessEngine::isCheckmate() const {
    bool checkmate = board.isInCheck(currentTurn) && !board.hasLegalMoves(currentTurn);
    if (checkmate) {
        std::cout << "Checkmate detected." << std::endl;
    }
    return checkmate;
}

bool ChessEngine::isStalemate() const {
    bool stalemate = !board.isInCheck(currentTurn) && !board.hasLegalMoves(currentTurn);
    if (stalemate) {
        std::cout << "Stalemate detected." << std::endl;
    }
    return stalemate;
}

bool ChessEngine::isWhiteTurn() const {
    return currentTurn;
}
