#include "AIPlayer.h"
#include <algorithm> // For std::max and std::min

AIPlayer::AIPlayer(Board& board, Move& move, int depth) : board(board), move(move), depth(depth) {}

MoveData AIPlayer::getBestMove(Color color) {
    int bestValue = (color == Color::White) ? -10000 : 10000;
    MoveData bestMove;
    std::vector<MoveData> validMoves = move.getAllValidMoves(color);

    for (const auto& m : validMoves) {
        // Perform the move
        Square temp = board.board[m.endY][m.endX];
        board.board[m.endY][m.endX] = board.board[m.startY][m.startX];
        board.board[m.startY][m.startX] = {Piece::Empty, Color::None};

        // Call minimax recursively and choose the maximum or minimum value
        int boardValue = minimax(depth - 1, color == Color::White ? Color::Black : Color::White, color == Color::Black);
        
        // Undo the move
        board.board[m.startY][m.startX] = board.board[m.endY][m.endX];
        board.board[m.endY][m.endX] = temp;

        if (color == Color::White) {
            if (boardValue > bestValue) {
                bestValue = boardValue;
                bestMove = m;
            }
        } else {
            if (boardValue < bestValue) {
                bestValue = boardValue;
                bestMove = m;
            }
        }
    }
    return bestMove;
}

int AIPlayer::minimax(int depth, Color color, bool isMaximizingPlayer) {
    if (depth == 0) {
        return evaluateBoard();
    }

    std::vector<MoveData> validMoves = move.getAllValidMoves(color);
    if (validMoves.empty()) {
        return evaluateBoard();
    }

    int bestValue = isMaximizingPlayer ? -10000 : 10000;
    for (const auto& m : validMoves) {
        // Perform the move
        Square temp = board.board[m.endY][m.endX];
        board.board[m.endY][m.endX] = board.board[m.startY][m.startX];
        board.board[m.startY][m.startX] = {Piece::Empty, Color::None};

        // Recurse
        int boardValue = minimax(depth - 1, color == Color::White ? Color::Black : Color::White, !isMaximizingPlayer);

        // Undo the move
        board.board[m.startY][m.startX] = board.board[m.endY][m.endX];
        board.board[m.endY][m.endX] = temp;

        if (isMaximizingPlayer) {
            bestValue = std::max(bestValue, boardValue);
        } else {
            bestValue = std::min(bestValue, boardValue);
        }
    }
    return bestValue;
}

int AIPlayer::evaluateBoard() const {
    int value = 0;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            const Square& square = board.board[y][x];
            if (square.piece != Piece::Empty) {
                int pieceValue = 0;
                switch (square.piece) {
                    case Piece::Pawn: pieceValue = 1; break;
                    case Piece::Knight: pieceValue = 3; break;
                    case Piece::Bishop: pieceValue = 3; break;
                    case Piece::Rook: pieceValue = 5; break;
                    case Piece::Queen: pieceValue = 9; break;
                    case Piece::King: pieceValue = 1000; break;
                    default: break;
                }
                value += (square.color == Color::White) ? pieceValue : -pieceValue;
            }
        }
    }
    return value;
}
