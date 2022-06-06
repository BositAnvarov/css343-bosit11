#include "SudokuOffspring.h"

SudokuOffspring::SudokuOffspring()
{
}

SudokuOffspring::~SudokuOffspring()
{
}

// implementation of makeOffspring function to make offspring from a puzzle
Puzzle& SudokuOffspring::makeOffspring(const Puzzle& parent, Puzzle& parentChild) const 
	{

	// using the = operator that has been overloaded, copy the values from sudoku objects
	(Sudoku&)parentChild = (Sudoku&)parent;
	int i = NULL;
	int sudokuNum = 9;

	// use loop to check every index
	while (i < sudokuNum)
	{
		int j = NULL;
		while (j < sudokuNum)
		{
			// 5% chance to change into random value between 1 and 9 for an index that is not fixed
			// using the random given from standard library we can get the percentage to change values
			if (rand() % 100 <= 5 && ((Sudoku&)parentChild).fixedGrid[i][j] == false)
			{
				((Sudoku&)parentChild).grid[i][j] = (rand() % 9) + 1;
			}
			j++;
		}
		i++;
	}

	// return the offspring
	return parentChild;
}