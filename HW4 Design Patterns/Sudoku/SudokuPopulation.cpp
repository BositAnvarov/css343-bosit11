#include "SudokuPopulation.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"

// constructor
SudokuPopulation::SudokuPopulation(int size, const Sudoku& sudoku) {

	// set the max size to be inputted
	int maxSize = 10000;
	if (size > maxSize)
	{
		// population size will be set to 10000 if inputted more
		populationSize = maxSize;
		size = maxSize;
	}
	else
	{	
		//give the size according to input
		populationSize = size;		
	}

	//add the sudoku to the vector
	sudokuObjects.push_back(sudoku);

	
	// use loop to add mutations according to the size
	int i = NULL;
	while (i < size)
	{
		SudokuFactory tmpF;
		Sudoku tmp;

		sudokuObjects.push_back((Sudoku &)tmpF.createPuzzle(sudoku, tmp));
		i++;
	}

	int greatestFit, worstFit;
	greatestFit = 0;
	worstFit = populationSize - 1;

	// sort the sudoku
	sudokuSort(greatestFit, worstFit); 

}

// implementation of the cull function 
void SudokuPopulation::cull() {
	int nSize = NULL;

	// if less than 10, new size is 1
	if (populationSize < 10)
	{
		nSize = 1;
	}
	// if more than 0, new size becomes population size divided by 10
	else if (populationSize / 10 > 0)
	{
		nSize = populationSize / 10;
	}
	
	

	// getting rid of the 90%  sudoku puzzles from the vector
	int i = populationSize;
	while (i > nSize)
	{
		sudokuObjects.pop_back();
		i--;
	}

	// give the population its new size
	populationSize = nSize;
}

// implementation of bestFitness function
int SudokuPopulation::bestFitness() const 
{
	// base case for empty population size
	if (populationSize == 0)
	{
		return 0;				
	}
	// if population size is not empty, return the sudoku with the best fitness number
	else 
	{
		SudokuFitness f;
		return f.howFit(sudokuObjects[0]);
	}
}

// implementation of newGeneration function
void SudokuPopulation::newGeneration(int x) {

	vector<Sudoku> tmpSudokuObjects;	
	SudokuFactory tmpF;

	
	int i = NULL;
	int maxSize = 10000;
	
	// store each sudoku puzzle into the temporary vector after being mutated x number of times
	while (i < x)
	{
		int j = NULL;
		while (j < populationSize)
		{
			if (tmpSudokuObjects.size() >= maxSize)
			{
				break;
			}

			else 
			{
				Sudoku tmp;
				tmpSudokuObjects.push_back((Sudoku&)tmpF.createPuzzle(((Sudoku&)sudokuObjects[j]), tmp));
			}
			j++;
		}
		i++;
	}

	//set the old vector into temporary vector by using the = operator
	sudokuObjects.empty();
	sudokuObjects = tmpSudokuObjects;
	populationSize = sudokuObjects.size();

	int greatestFit, worstFit;
	greatestFit = 0;
	worstFit = populationSize - 1;

	// sort the sudoku
	sudokuSort(greatestFit, worstFit);
}

const Puzzle& SudokuPopulation::bestIndividual() 
{
	// return the best fitness sudoku
	return sudokuObjects[0];
}

// sorts the sudoku using the fitness numbers
void SudokuPopulation::sudokuSort(int left, int right) {

	SudokuFitness tmpSF;
	Sudoku tmpS;

	
	int l = left, r = right;
	int pivot = tmpSF.howFit(sudokuObjects[(left + right) / 2]);
	

	while (l <= r) {

		while (tmpSF.howFit(sudokuObjects[l]) < pivot)
		{
			l++;
		}
		while (tmpSF.howFit(sudokuObjects[r]) > pivot)
		{
			r--;
		}

		if (true) {

			// set the temporary sudoku into the sudokuObjects
			tmpS = sudokuObjects[l];
			sudokuObjects[l] = sudokuObjects[r];
			sudokuObjects[r] = tmpS;
			l++;
			r--;
		}
	}

	// recursively call sudoku to sort from best fit to worst fit
	if (left < r)
	{
		sudokuSort(left, r);
	}
	else if (l < right)
	{
		sudokuSort(l, right);
	}
}