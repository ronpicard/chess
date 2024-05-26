// src/main.cpp
#include "ChessEngine.h"
#include <iostream>

int main() {
    ChessEngine engine;
    engine.start();
    engine.movePiece(1, 0, 3, 0); // Move white pawn from a2 to a4
    engine.movePiece(6, 0, 4, 0); // Move black pawn from a7 to a5
    return 0;
}
