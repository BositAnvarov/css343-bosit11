#ifndef PUZZLE_FACTORY_H
#define PUZZLE_FACTORY_H

#include "Puzzle.h"

class PuzzleFactory
{
public:
	
	// create random puzzles based on original sudoku, needs to be overritten by its subclass
	virtual Puzzle& createPuzzle(const Puzzle& s, Puzzle& c) = 0;
};

#endif
