#include <iostream>
#include <random>
#include <vector>
#include "Board.h"
#include "Move.h"

void printValidMoves(const std::vector<MoveData>& moves);
MoveData getRandomMove(const std::vector<MoveData>& validMoves);

int main() {
    Board board;
    Move move(board);
    bool whiteTurn = true;

    while (true) {
        board.printBoard();

        Color currentColor = whiteTurn ? Color::White : Color::Black;
        std::vector<MoveData> validMoves = move.getAllValidMoves(currentColor);

        if (validMoves.empty()) {
            std::cout << (whiteTurn ? "White" : "Black") << " has no valid moves. Game over." << std::endl;
            break;
        }

        MoveData selectedMove = getRandomMove(validMoves);

        std::cout << (whiteTurn ? "White" : "Black") << "'s move: (" 
                  << selectedMove.startX << ", " << selectedMove.startY << ") to ("
                  << selectedMove.endX << ", " << selectedMove.endY << ")" << std::endl;

        if (move.makeMove(selectedMove.startX, selectedMove.startY, selectedMove.endX, selectedMove.endY)) {
            std::cout << "Move successful" << std::endl;
        } else {
            std::cout << "Move failed" << std::endl;
            continue; // If the move is invalid, the same player tries again
        }

        board.printBoard();

        std::cout << "Do you want to continue? (y/n): ";
        char cont;
        std::cin >> cont;
        if (cont != 'y' && cont != 'Y') {
            break; // Exit the loop if the user does not want to continue
        }

        whiteTurn = !whiteTurn; // Switch turns
    }

    return 0;
}

void printValidMoves(const std::vector<MoveData>& moves) {
    for (const auto& move : moves) {
        std::cout << "Move from (" << move.startX << ", " << move.startY << ") to (" << move.endX << ", " << move.endY << ")" << std::endl;
    }
}

MoveData getRandomMove(const std::vector<MoveData>& validMoves) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, validMoves.size() - 1);
    return validMoves[dist(gen)];
}
