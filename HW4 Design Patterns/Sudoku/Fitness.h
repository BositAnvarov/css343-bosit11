#ifndef FITNESS_H
#define FITNESS_H 

#include "Puzzle.h"

class Fitness 
{
public:

	// This is a virtual function to be overritten in the sub class
	// keeps track of the puzzle's fitness
	virtual int howFit(const Puzzle& puzzle) const = 0;	
};

#endif