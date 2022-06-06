#include "SudokuFactory.h"

SudokuFactory::SudokuFactory()
{
}

SudokuFactory::~SudokuFactory()
{
}

// Implementation of a createPuzzle function to mutate the first sudoku object
Puzzle& SudokuFactory::createPuzzle(const Puzzle& s,  Puzzle& c) {

	// child type SudokuOffspring
	SudokuOffspring child;

	// return the mutation of first puzzle
	return child.makeOffspring((Sudoku&) s, (Sudoku&) c);
}