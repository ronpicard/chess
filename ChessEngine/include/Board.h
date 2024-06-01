#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

enum class Piece {
    Empty, Pawn, Knight, Bishop, Rook, Queen, King
};

enum class Color {
    None, White, Black
};

struct Square {
    Piece piece;
    Color color;
};

class Board {
public:
    Board();
    void printBoard() const;
    std::vector<std::vector<Square>> board;

private:
    void initializeBoard();
};

#endif // BOARD_H
