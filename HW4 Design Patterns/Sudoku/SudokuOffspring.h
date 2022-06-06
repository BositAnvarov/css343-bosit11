#ifndef SUDOKU_OFFSPRING_H
#define SUDOKU_OFFSPRING_H

#include "Reproduction.h"
#include "Sudoku.h"
#include <stdlib.h>

// SudokuOffspring inherits from Reproduction
class SudokuOffspring : public Reproduction 
{
public:

	// default constructor and destructor 
	SudokuOffspring();
	~SudokuOffspring();

	// makeOffspring function from Reprudoction to be implemented
	Puzzle& makeOffspring(const Puzzle& parent, Puzzle& parentChild) const;

};
#endif
