#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Board.h"

class Evaluator {
public:
    int evaluate(const Board& board) const;
};

#endif // EVALUATOR_H