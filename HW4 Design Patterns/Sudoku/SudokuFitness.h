#ifndef SUDOKU_FITNESS_H
#define SUDOKU_FTINESS_H

#include "Fitness.h"
#include "Sudoku.h"
#include <iostream>

// SudokuFitness inherits from Fitness class
class SudokuFitness : public Fitness 
{
public:

	// howFit function from Fitness to be implemented
	int howFit(const Puzzle& puzzle) const;

};
#endif