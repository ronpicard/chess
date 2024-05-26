// src/Piece.cpp
#include "Piece.h"

Piece::Piece(char symbol) : symbol(symbol) {}

char Piece::getSymbol() const {
    return symbol;
}
