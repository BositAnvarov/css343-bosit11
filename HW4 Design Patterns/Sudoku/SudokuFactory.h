#ifndef SUDOKU_FACTORY_H
#define SUDOKU_FACTORY_H

#include "PuzzleFactory.h"
#include "Puzzle.h"
#include "SudokuOffspring.h"

// SudokuFactory inherits from PuzzleFactory 
class SudokuFactory : public PuzzleFactory 
{
public:

	// default constuctor and destructor
	SudokuFactory();
	~SudokuFactory();


	// createPuzzle from PuzzleFactory to be implemented 
	Puzzle& createPuzzle(const Puzzle& s, Puzzle& c);

};
#endif