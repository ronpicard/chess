// include/Piece.h
#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece {
public:
    Piece(char symbol);
    char getSymbol() const;
private:
    char symbol;
};

#endif // PIECE_H
