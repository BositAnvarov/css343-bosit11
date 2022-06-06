#ifndef POPULATION_H
#define POPULATION_H

#include "Fitness.h"
#include "Puzzle.h"
#include <list>

class Population 
{
public:

	
	// required functions for the population class that has been instantiated as pute virtual 
	// to be overritten in its subclass SudokuPopulation
	virtual void newGeneration(int) = 0;
	virtual const Puzzle& bestIndividual() = 0;
	virtual void cull() = 0;
	virtual int bestFitness() const = 0;

};


#endif