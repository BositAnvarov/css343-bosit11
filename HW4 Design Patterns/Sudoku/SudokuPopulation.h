#ifndef SUDOKU_POPULATION_H
#define SUDOKU_POPULATION_H

#include "Population.h"
#include "Sudoku.h"
#include <vector>

using namespace std;

// SudokuPopulation inherits from Population
class SudokuPopulation : public Population 
{
public:
	SudokuPopulation(int size, const Sudoku& s);

	// overriding functions from Population
	void cull();
	int bestFitness() const;
	void newGeneration(int);
	const Puzzle& bestIndividual();
	
	// sudoku sorting function
	void sudokuSort(int left, int right);	

private:

	vector<Sudoku> sudokuObjects;
	// to store population size
	int populationSize;
	
};
#endif