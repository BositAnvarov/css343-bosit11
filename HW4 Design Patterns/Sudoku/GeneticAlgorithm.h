#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORTIHN_H

#include "Sudoku.h"
#include "SudokuFactory.h"
#include "Puzzle.h"
#include "PuzzleFactory.h"
#include "Fitness.h"
#include "SudokuPopulation.h"
#include "SudokuFitness.h"
#include "Population.h"


#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class GeneticAlgorithm 
{

public:

	//Takes in the values passed through the command line and output and runs the algorithm 
	GeneticAlgorithm(int size, int num, string fileName);
};
#endif