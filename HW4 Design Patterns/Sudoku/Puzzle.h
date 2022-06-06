#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>

using namespace std;

class Puzzle
{
public:

	// read function, to read the characters from a given "textFile.txt", needs to be overritten 
	virtual void read(ifstream& textFile) = 0;
	// print function, to print the sudoku in a eye pleasing way, needs to be overritten
	virtual void print() const = 0;

};
#endif
