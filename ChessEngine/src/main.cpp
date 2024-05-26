#include "ChessEngine.h"
#include <iostream>

int main() {
    ChessEngine engine;
    engine.start();
    
    int depth = 3; // Example depth for the minimax algorithm

    while (true) {
        if (engine.isCheckmate()) {
            std::cout << "Checkmate! " << (engine.isWhiteTurn() ? "Black" : "White") << " wins!" << std::endl;
            break;
        }

        if (engine.isStalemate()) {
            std::cout << "Stalemate!" << std::endl;
            break;
        }

        auto bestMove = engine.findBestMove(depth);
        
        std::cout << "Best move: (" << std::get<0>(bestMove) << ", " << std::get<1>(bestMove)
                  << ") -> (" << std::get<2>(bestMove) << ", " << std::get<3>(bestMove) << ")" << std::endl;
        
        bool moveSuccess = engine.movePiece(std::get<0>(bestMove), std::get<1>(bestMove), std::get<2>(bestMove), std::get<3>(bestMove));
        std::cout << "Move " << (moveSuccess ? "succeeded" : "failed") << std::endl;

        // Print the current board state after each move
        engine.printBoard();

        if (engine.checkDrawByRepetition()) {
            std::cout << "Game drawn by repetition!" << std::endl;
            break;
        }

        // Add a break condition to prevent an infinite loop for demonstration purposes
        // In a real game, you should check for endgame conditions
        char response;
        std::cout << "Continue (y/n)? ";
        std::cin >> response;
        if (response != 'y') break;
    }

    return 0;
}
