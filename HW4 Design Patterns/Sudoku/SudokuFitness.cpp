#include "SudokuFitness.h"

// implementation of howFit function which calculates the fitness number of the sudoku
int SudokuFitness::howFit(const Puzzle& puzzle) const {

	// to keep track of the fitness number
	int fitnessRank = 0;
	// boolean array to track numbers in a row and column
	bool rowNums[10];		
	bool columnNums[10];
	int f = NULL;
	int i = NULL;
	

	//set the grid values to false
	while (f < 10) 
	{
		rowNums[f] = false;
		columnNums[f] = false;
		f++;
	}

	// use loop to check every index in the grid
	while (i < 9)
	{
		int j = NULL;
		while (j < 9)
		{
			
			// add one for every hole, duplicates in a row or column
			if (((Sudoku&)puzzle).grid[i][j] != 0) 
			{

				if (rowNums[((Sudoku&)puzzle).grid[i][j]] == false) 
				{
					rowNums[((Sudoku&)puzzle).grid[i][j]] = true;
				}
				else 
				{
					fitnessRank++;
				}

				if (columnNums[((Sudoku&)puzzle).grid[j][i]] == false)
				{
					columnNums[((Sudoku&)puzzle).grid[j][i]] = true;
				}
				else
				{
					fitnessRank++;
				}
			}
			else fitnessRank++;
			j++;
		}
		

		// make the values in the index false
		int ff = NULL;
		while (ff < 10)
		{
			rowNums[ff] = false;
			columnNums[ff] = false;
			ff++;
		}
		
		i++;
	}
	
	//return the fitness number
	return fitnessRank; 
}