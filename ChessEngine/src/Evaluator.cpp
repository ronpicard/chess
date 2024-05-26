#include "Evaluator.h"

int Evaluator::evaluate(const Board& board) const {
    int score = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board.getPiece(i, j) != nullptr) {
                char symbol = board.getPiece(i, j)->getSymbol();
                switch (symbol) {
                    case 'P': score += 1; break;
                    case 'R': score += 5; break;
                    case 'N': score += 3; break;
                    case 'B': score += 3; break;
                    case 'Q': score += 9; break;
                    case 'K': score += 1000; break;
                    case 'p': score -= 1; break;
                    case 'r': score -= 5; break;
                    case 'n': score -= 3; break;
                    case 'b': score -= 3; break;
                    case 'q': score -= 9; break;
                    case 'k': score -= 1000; break;
                }
            }
        }
    }
    return score;
}