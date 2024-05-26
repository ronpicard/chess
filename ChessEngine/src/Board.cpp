#include "Board.h"
#include <iostream>
#include <memory>
#include <utility>
#include <cctype>
#include <cmath>
#include <sstream>

Board::Board() {
    board.resize(8);
    for (auto& row : board) {
        row.resize(8);
    }
}

void Board::initialize() {
    // Initialize pawns
    for (int i = 0; i < 8; ++i) {
        board[1][i] = std::make_unique<Piece>('P'); // White pawns
        board[6][i] = std::make_unique<Piece>('p'); // Black pawns
    }

    // Initialize rooks
    board[0][0] = std::make_unique<Piece>('R'); // White rook
    board[0][7] = std::make_unique<Piece>('R');
    board[7][0] = std::make_unique<Piece>('r'); // Black rook
    board[7][7] = std::make_unique<Piece>('r');

    // Initialize knights
    board[0][1] = std::make_unique<Piece>('N'); // White knight
    board[0][6] = std::make_unique<Piece>('N');
    board[7][1] = std::make_unique<Piece>('n'); // Black knight
    board[7][6] = std::make_unique<Piece>('n');

    // Initialize bishops
    board[0][2] = std::make_unique<Piece>('B'); // White bishop
    board[0][5] = std::make_unique<Piece>('B');
    board[7][2] = std::make_unique<Piece>('b'); // Black bishop
    board[7][5] = std::make_unique<Piece>('b');

    // Initialize queens
    board[0][3] = std::make_unique<Piece>('Q'); // White queen
    board[7][3] = std::make_unique<Piece>('q'); // Black queen

    // Initialize kings
    board[0][4] = std::make_unique<Piece>('K'); // White king
    board[7][4] = std::make_unique<Piece>('k'); // Black king
}

bool Board::movePiece(int startX, int startY, int endX, int endY) {
    if (!isMoveLegal(startX, startY, endX, endY)) {
        return false;
    }

    // Move the piece using std::move
    board[endX][endY] = std::move(board[startX][startY]);
    board[startX][startY] = nullptr;
    return true;
}

bool Board::isMoveLegal(int startX, int startY, int endX, int endY) const {
    // Check if the move is within the bounds of the board
    if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 ||
        endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false;
    }

    if (board[startX][startY] == nullptr) {
        return false;
    }

    char piece = board[startX][startY]->getSymbol();
    bool isWhite = isupper(piece);

    // Check if the destination square contains a piece of the same color
    if (board[endX][endY] != nullptr) {
        char targetPiece = board[endX][endY]->getSymbol();
        if ((isWhite && isupper(targetPiece)) || (!isWhite && islower(targetPiece))) {
            return false; // Can't capture own piece
        }
    }

    switch (tolower(piece)) {
        case 'p': return isPawnMoveLegal(startX, startY, endX, endY);
        case 'r': return isRookMoveLegal(startX, startY, endX, endY);
        case 'n': return isKnightMoveLegal(startX, startY, endX, endY);
        case 'b': return isBishopMoveLegal(startX, startY, endX, endY);
        case 'q': return isQueenMoveLegal(startX, startY, endX, endY);
        case 'k': return isKingMoveLegal(startX, startY, endX, endY);
        default: return false;
    }
}

bool Board::isPathClear(int startX, int startY, int endX, int endY) const {
    int dx = endX - startX;
    int dy = endY - startY;
    int steps = std::max(std::abs(dx), std::abs(dy));
    int stepX = (dx == 0) ? 0 : dx / std::abs(dx);
    int stepY = (dy == 0) ? 0 : dy / std::abs(dy);

    for (int i = 1; i < steps; ++i) {
        int x = startX + i * stepX;
        int y = startY + i * stepY;
        if (board[x][y] != nullptr) {
            return false;
        }
    }

    return true;
}

bool Board::isPawnMoveLegal(int startX, int startY, int endX, int endY) const {
    // Check if the move is within the bounds of the board
    if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false;
    }

    char piece = board[startX][startY]->getSymbol();
    bool isWhite = isupper(piece);
    int direction = isWhite ? -1 : 1;
    int startRow = isWhite ? 6 : 1;

    int dx = endX - startX;
    int dy = endY - startY;

    // Normal move (one square forward)
    if (dy == 0 && dx == direction && board[endX][endY] == nullptr) {
        return true;
    }

    // Double move from starting position (two squares forward)
    if (startX == startRow && dy == 0 && dx == 2 * direction &&
        board[endX][endY] == nullptr && board[startX + direction][startY] == nullptr) {
        return true;
    }

    // Capture move (one square diagonally)
    if (std::abs(dy) == 1 && dx == direction && board[endX][endY] != nullptr) {
        return true;
    }

    return false;
}

bool Board::isRookMoveLegal(int startX, int startY, int endX, int endY) const {
    // Check if the move is within the bounds of the board
    if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false;
    }

    if (startX == endX || startY == endY) {
        return isPathClear(startX, startY, endX, endY);
    }
    return false;
}

bool Board::isKnightMoveLegal(int startX, int startY, int endX, int endY) const {
    // Check if the move is within the bounds of the board
    if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false;
    }

    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

bool Board::isBishopMoveLegal(int startX, int startY, int endX, int endY) const {
    // Check if the move is within the bounds of the board
    if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false;
    }

    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);
    return dx == dy && isPathClear(startX, startY, endX, endY);
}

bool Board::isQueenMoveLegal(int startX, int startY, int endX, int endY) const {
    // Check if the move is within the bounds of the board
    if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false;
    }

    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);
    return (dx == dy || startX == endX || startY == endY) && isPathClear(startX, startY, endX, endY);
}

bool Board::isKingMoveLegal(int startX, int startY, int endX, int endY) const {
    // Check if the move is within the bounds of the board
    if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false;
    }

    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);
    return dx <= 1 && dy <= 1;
}

void Board::printBoard() const {
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

Board Board::clone() const {
    Board newBoard;
    newBoard.board.resize(8);
    for (int i = 0; i < 8; ++i) {
        newBoard.board[i].resize(8);
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] != nullptr) {
                newBoard.board[i][j] = std::make_unique<Piece>(board[i][j]->getSymbol());
            }
        }
    }
    return newBoard;
}

Piece* Board::getPiece(int x, int y) const {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return nullptr;
    }
    return board[x][y].get();
}

std::string Board::getBoardStateHash() const {
    std::stringstream ss;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] != nullptr) {
                ss << board[i][j]->getSymbol();
            } else {
                ss << '.';
            }
        }
    }
    return ss.str();
}

bool Board::isInCheck(bool isWhite) const {
    int kingX = -1, kingY = -1;
    char kingSymbol = isWhite ? 'K' : 'k';

    // Find the king
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] != nullptr && board[i][j]->getSymbol() == kingSymbol) {
                kingX = i;
                kingY = j;
                break;
            }
        }
    }

    // Check if any opposing piece can move to the king's position
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] != nullptr) {
                char piece = board[i][j]->getSymbol();
                // Only consider opponent's pieces
                if (isWhite != isupper(piece)) {
                    if (isMoveLegal(i, j, kingX, kingY)) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool Board::hasLegalMoves(bool isWhite) const {
    for (int startX = 0; startX < 8; ++startX) {
        for (int startY = 0; startY < 8; ++startY) {
            if (board[startX][startY] != nullptr && (isWhite == isupper(board[startX][startY]->getSymbol()))) {
                for (int endX = 0; endX < 8; ++endX) {
                    for (int endY = 0; endY < 8; ++endY) {
                        if (isMoveLegal(startX, startY, endX, endY)) {
                            Board newBoard = clone();
                            newBoard.movePiece(startX, startY, endX, endY);
                            if (!newBoard.isInCheck(isWhite)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
