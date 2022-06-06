#ifndef REPRODUCTION_H
#define	REPRODUCTION_H

#include "Puzzle.h"

class Reproduction 
{
public:
	
	// virtual function, makes an offspring based on the original sudoku with modification
	virtual Puzzle& makeOffspring(const Puzzle& parent , Puzzle& parentChild) const = 0;

};
#endif