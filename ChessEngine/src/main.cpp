#include <iostream>
#include <random>
#include "Board.h"
#include "Move.h"

bool makeRandomMove(Move& move, bool whiteTurn);

int main() {
    Board board;
    Move move(board);
    bool whiteTurn = true;

    while (true) {
        board.printBoard();

        std::cout << "Do you want to continue? (y/n): ";
        char cont;
        std::cin >> cont;
        if (cont != 'y' && cont != 'Y') {
            break; // Exit the loop if the user does not want to continue
        }

        whiteTurn = !whiteTurn; // Switch turns

        // Make a random move for the opposite player
        if (!makeRandomMove(move, whiteTurn)) {
            std::cout << "No valid moves available for " << (whiteTurn ? "White" : "Black") << std::endl;
            break;
        }

        whiteTurn = !whiteTurn; // Switch back to the user's turn
    }

    return 0;
}

bool makeRandomMove(Move& move, bool whiteTurn) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 7);

    for (int attempt = 0; attempt < 100; ++attempt) { // Try up to 100 random moves
        int startX = dist(gen);
        int startY = dist(gen);
        int endX = dist(gen);
        int endY = dist(gen);

        const Square& startSquare = move.board.board[startY][startX];
        if ((whiteTurn && startSquare.color == Color::White) || (!whiteTurn && startSquare.color == Color::Black)) {
            if (move.makeMove(startX, startY, endX, endY)) {
                std::cout << (whiteTurn ? "White" : "Black") << " made a random move from (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ")" << std::endl;
                return true;
            }
        }
    }

    return false; // No valid move found after 100 attempts
}
