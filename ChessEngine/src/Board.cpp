// src/Board.cpp
#include "Board.h"
#include <iostream>
#include <memory>
#include <utility>

Board::Board() {
    board.resize(8);
    for (auto& row : board) {
        row.resize(8);
    }
}

void Board::initialize() {
    // Initialize pawns
    for (int i = 0; i < 8; ++i) {
        board[1][i] = std::make_unique<Piece>('P');
        board[6][i] = std::make_unique<Piece>('p');
    }

    // Initialize rooks
    board[0][0] = std::make_unique<Piece>('R');
    board[0][7] = std::make_unique<Piece>('R');
    board[7][0] = std::make_unique<Piece>('r');
    board[7][7] = std::make_unique<Piece>('r');

    // Initialize knights
    board[0][1] = std::make_unique<Piece>('N');
    board[0][6] = std::make_unique<Piece>('N');
    board[7][1] = std::make_unique<Piece>('n');
    board[7][6] = std::make_unique<Piece>('n');

    // Initialize bishops
    board[0][2] = std::make_unique<Piece>('B');
    board[0][5] = std::make_unique<Piece>('B');
    board[7][2] = std::make_unique<Piece>('b');
    board[7][5] = std::make_unique<Piece>('b');

    // Initialize queens
    board[0][3] = std::make_unique<Piece>('Q');
    board[7][3] = std::make_unique<Piece>('q');

    // Initialize kings
    board[0][4] = std::make_unique<Piece>('K');
    board[7][4] = std::make_unique<Piece>('k');
}

bool Board::movePiece(int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 ||
        endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false;
    }

    if (board[startX][startY] == nullptr) {
        return false;
    }

    // Move the piece using std::move
    board[endX][endY] = std::move(board[startX][startY]);
    board[startX][startY] = nullptr;
    return true;
}

void Board::printBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] != nullptr) {
                std::cout << board[i][j]->getSymbol() << " ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}
