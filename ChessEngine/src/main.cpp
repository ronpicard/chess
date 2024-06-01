#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <unistd.h>  // For getcwd
#include "Board.h"
#include "Move.h"
#include "AIPlayer.h"

void printValidMoves(const std::vector<MoveData>& moves);
MoveData getRandomMove(const std::vector<MoveData>& validMoves);

int main() {
    // Check the current working directory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::cout << "Current working directory: " << cwd << std::endl;
    } else {
        perror("getcwd() error");
        return 1;
    }

    // Read the configuration from the text file
    std::ifstream config_file("config.txt");
    if (!config_file.is_open()) {
        std::cerr << "Could not open the config file!" << std::endl;
        return 1;
    }
    
    int depth = 0;
    std::string line;
    while (std::getline(config_file, line)) {
        std::istringstream iss(line);
        std::string key;
        if (std::getline(iss, key, '=') && key == "depth") {
            iss >> depth;
        }
    }

    if (depth == 0) {
        std::cerr << "Invalid depth value in config file!" << std::endl;
        return 1;
    }
    
    Board board;
    Move move(board);
    AIPlayer aiPlayer(board, move, depth); // Use the depth from the config file
    bool whiteTurn = true;

    while (true) {
        board.printBoard();

        Color currentColor = whiteTurn ? Color::White : Color::Black;
        if (move.isCheckmate(currentColor)) {
            std::cout << (whiteTurn ? "White" : "Black") << " is in checkmate. Game over." << std::endl;
            break;
        }
        if (move.isStalemate(currentColor) || move.isInsufficientMaterial() || move.isThreefoldRepetition()) {
            std::cout << "The game is a draw. Game over." << std::endl;
            break;
        }
        if (move.isKingInCheck(currentColor)) {
            std::cout << (whiteTurn ? "White" : "Black") << " is in check." << std::endl;
        }

        MoveData selectedMove;
        if (currentColor == Color::White) {
            selectedMove = aiPlayer.getBestMove(currentColor);
        } else {
            selectedMove = aiPlayer.getBestMove(currentColor);
        }

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
