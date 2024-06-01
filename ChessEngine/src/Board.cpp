#include "Board.h"
#include <iostream>

Board::Board() {
    initializeBoard();
}

void Board::initializeBoard() {
    // Initialize an 8x8 board with empty squares
    board.resize(8, std::vector<Square>(8, {Piece::Empty, Color::None}));

    // Set up pawnsre
    for (int i = 0; i < 8; ++i) {
        board[1][i] = {Piece::Pawn, Color::White};
        board[6][i] = {Piece::Pawn, Color::Black};
    }

    // Set up other pieces
    std::vector<Piece> pieces = {Piece::Rook, Piece::Knight, Piece::Bishop, Piece::Queen, Piece::King, Piece::Bishop, Piece::Knight, Piece::Rook};

    for (int i = 0; i < 8; ++i) {
        board[0][i] = {pieces[i], Color::White};
        board[7][i] = {pieces[i], Color::Black};
    }
}

void Board::printBoard() const {
    for (const auto& row : board) {
        for (const auto& square : row) {
            char pieceChar;
            switch (square.piece) {
                case Piece::Empty: pieceChar = '.'; break;
                case Piece::Pawn: pieceChar = 'P'; break;
                case Piece::Knight: pieceChar = 'N'; break;
                case Piece::Bishop: pieceChar = 'B'; break;
                case Piece::Rook: pieceChar = 'R'; break;
                case Piece::Queen: pieceChar = 'Q'; break;
                case Piece::King: pieceChar = 'K'; break;
                default: pieceChar = '?'; break;
            }

            if (square.color == Color::Black) {
                pieceChar = tolower(pieceChar);
            }

            std::cout << pieceChar << " ";
        }
        std::cout << std::endl;
    }

}
