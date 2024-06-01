#include "Move.h"

Move::Move(Board& board) : board(board) {}

bool Move::makeMove(int startX, int startY, int endX, int endY) {
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

std::vector<MoveData> Move::getAllValidMoves(Color color) const {
    std::vector<MoveData> validMoves;

    for (int startY = 0; startY < 8; ++startY) {
        for (int startX = 0; startX < 8; ++startX) {
            const Square& startSquare = board.board[startY][startX];
            if (startSquare.color != color) {
                continue; // Skip pieces of the opposite color and empty squares
            }

            for (int endY = 0; endY < 8; ++endY) {
                for (int endX = 0; endX < 8; ++endX) {
                    if (isLegalMove(startX, startY, endX, endY) && moveResolvesCheck({startX, startY, endX, endY}, color)) {
                        validMoves.push_back({startX, startY, endX, endY});
                    }
                }
            }
        }
    }

    return validMoves;
}

bool Move::moveResolvesCheck(const MoveData& move, Color color) const {
    // Perform the move
    Square temp = board.board[move.endY][move.endX];
    board.board[move.endY][move.endX] = board.board[move.startY][move.startX];
    board.board[move.startY][move.startX] = {Piece::Empty, Color::None};

    bool stillInCheck = isKingInCheck(color);

    // Undo the move
    board.board[move.startY][move.startX] = board.board[move.endY][move.endX];
    board.board[move.endY][move.endX] = temp;

    return !stillInCheck;
}

bool Move::isKingInCheck(Color color) const {
    // Find the position of the king
    int kingX = -1, kingY = -1;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (board.board[y][x].piece == Piece::King && board.board[y][x].color == color) {
                kingX = x;
                kingY = y;
                break;
            }
        }
        if (kingX != -1) break;
    }

    if (kingX == -1) return false; // King not found (should not happen in a valid game)

    // Check if any of the opponent's pieces can move to the king's position
    Color opponentColor = (color == Color::White) ? Color::Black : Color::White;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            if (board.board[y][x].color == opponentColor && isLegalMove(x, y, kingX, kingY)) {
                return true;
            }
        }
    }

    return false;
}

bool Move::isCheckmate(Color color) const {
    if (!isKingInCheck(color)) {
        return false;
    }

    // Check if the player can make any valid move to get out of check
    std::vector<MoveData> validMoves = getAllValidMoves(color);
    for (const auto& move : validMoves) {
        if (moveResolvesCheck(move, color)) {
            return false;
        }
    }

    return true;
}

bool Move::isStalemate(Color color) const {
    if (isKingInCheck(color)) {
        return false;
    }

    // Check if the player can make any valid move
    std::vector<MoveData> validMoves = getAllValidMoves(color);
    return validMoves.empty();
}

bool Move::isInsufficientMaterial() const {
    int whiteBishops = 0, whiteKnights = 0, blackBishops = 0, blackKnights = 0;
    bool whiteHasOtherPieces = false, blackHasOtherPieces = false;

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            const Square& square = board.board[y][x];
            if (square.piece == Piece::Empty) continue;

            if (square.color == Color::White) {
                if (square.piece == Piece::Bishop) whiteBishops++;
                else if (square.piece == Piece::Knight) whiteKnights++;
                else if (square.piece != Piece::King) whiteHasOtherPieces = true;
            } else {
                if (square.piece == Piece::Bishop) blackBishops++;
                else if (square.piece == Piece::Knight) blackKnights++;
                else if (square.piece != Piece::King) blackHasOtherPieces = true;
            }
        }
    }

    if (whiteHasOtherPieces || blackHasOtherPieces) return false;

    if ((whiteBishops <= 1 && whiteKnights <= 1) && (blackBishops <= 1 && blackKnights <= 1)) {
        return true;
    }

    return false;
}
