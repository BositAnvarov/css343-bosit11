#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <fstream>
#include "Puzzle.h"

using namespace std;

// Sudoku inherits from Puzzle
class Sudoku : public Puzzle 
{
public:
	
	// default constuctor
	Sudoku();	
	~Sudoku();

	// methods overritten from puzzle
	void read(ifstream& textFile);
	void print() const;

	// Overloading the = operator to copy sudoku objects
	Sudoku& operator=(const Sudoku& rhs);

	//2D array to represent sudoku grid
	int grid[9][9];
	bool fixedGrid[9][9];

};

#endif
