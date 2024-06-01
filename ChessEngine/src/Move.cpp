#include "Move.h"

Move::Move(Board& board) : board(board) {}

bool Move::makeMove(int startX, int startY, int endX, int endY) {
    // Validate positions (simple bounds check for now)
    if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 ||
        endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false;
    }

    if (!isLegalMove(startX, startY, endX, endY)) {
        return false;
    }

    // Perform the move
    board.board[endY][endX] = board.board[startY][startX];
    board.board[startY][startX] = {Piece::Empty, Color::None};

    return true;
}

bool Move::isLegalMove(int startX, int startY, int endX, int endY) const {
    const Square& startSquare = board.board[startY][startX];
    const Square& endSquare = board.board[endY][endX];

    if (startSquare.color == endSquare.color) {
        return false; // Cannot take a piece of the same color
    }

    switch (startSquare.piece) {
        case Piece::Pawn:
            return isLegalPawnMove(startX, startY, endX, endY);
        case Piece::Knight:
            return isLegalKnightMove(startX, startY, endX, endY);
        case Piece::Bishop:
            return isLegalBishopMove(startX, startY, endX, endY);
        case Piece::Rook:
            return isLegalRookMove(startX, startY, endX, endY);
        case Piece::Queen:
            return isLegalQueenMove(startX, startY, endX, endY);
        case Piece::King:
            return isLegalKingMove(startX, startY, endX, endY);
        default:
            return false;
    }
}

bool Move::isLegalPawnMove(int startX, int startY, int endX, int endY) const {
    int direction = (board.board[startY][startX].color == Color::White) ? 1 : -1;

    // Standard one-square move forward
    if (endX == startX && endY == startY + direction && board.board[endY][endX].piece == Piece::Empty) {
        return true;
    }

    // Two-square move forward from starting position
    if ((startY == 1 && direction == 1 || startY == 6 && direction == -1) &&
        endX == startX && endY == startY + 2 * direction && board.board[startY + direction][startX].piece == Piece::Empty && board.board[endY][endX].piece == Piece::Empty) {
        return true;
    }

    // Capture move
    if ((endX == startX + 1 || endX == startX - 1) && endY == startY + direction &&
        board.board[endY][endX].color != board.board[startY][startX].color && board.board[endY][endX].piece != Piece::Empty) {
        return true;
    }

    return false;
}

bool Move::isLegalKnightMove(int startX, int startY, int endX, int endY) const {
    int dx = abs(endX - startX);
    int dy = abs(endY - startY);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

bool Move::isLegalBishopMove(int startX, int startY, int endX, int endY) const {
    int dx = abs(endX - startX);
    int dy = abs(endY - startY);
    return dx == dy && isPathClear(startX, startY, endX, endY);
}

bool Move::isLegalRookMove(int startX, int startY, int endX, int endY) const {
    return (startX == endX || startY == endY) && isPathClear(startX, startY, endX, endY);
}

bool Move::isLegalQueenMove(int startX, int startY, int endX, int endY) const {
    return (isLegalRookMove(startX, startY, endX, endY) || isLegalBishopMove(startX, startY, endX, endY));
}

bool Move::isLegalKingMove(int startX, int startY, int endX, int endY) const {
    int dx = abs(endX - startX);
    int dy = abs(endY - startY);
    return dx <= 1 && dy <= 1;
}

bool Move::isPathClear(int startX, int startY, int endX, int endY) const {
    int dx = (endX - startX) != 0 ? (endX - startX) / abs(endX - startX) : 0;
    int dy = (endY - startY) != 0 ? (endY - startY) / abs(endY - startY) : 0;

    int x = startX + dx;
    int y = startY + dy;

    while (x != endX || y != endY) {
        if (board.board[y][x].piece != Piece::Empty) {
            return false;
        }
        x += dx;
        y += dy;
    }

    return true;
}