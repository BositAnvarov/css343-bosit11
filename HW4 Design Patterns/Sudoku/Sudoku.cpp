#include "Sudoku.h"

using namespace std;

Sudoku::Sudoku()
{

	// Nested loop to set the values in the sudoku grid to 0 and false
	int i = NULL;
	while (i < 9)
	{
		int j = 0;
		while (j < 9)
		{
			grid[i][j] = 0;
			fixedGrid[i][j] = false;
			j++;
		}
		
		i++;
	}	
}

Sudoku::~Sudoku()
{
}

// This is an implementation of the read file, it reads characters form the textfile and sets the grid accordingly
void Sudoku::read(ifstream& textFile) 
{
	
	// Variables to keep track of characters
	char number;
	int i = 0, j = 0;

	//looping through the given file to fill sudoku grid with characters 
	while (!textFile.eof())
	{

		number = textFile.get();

		//If the number is between 0 and 9 fill the grid 
		if (number - '0' >= 0 && number - '0' <= 9) 
		{
			//If the number is non-zero update the fixedGrid 
			if (number - '0' != 0)
			{
				fixedGrid[i][j] = true;
			}

			grid[i][j] = number - '0';
			j++;

			if (j == 9) 
			{
				j = 0;
				i++;
			}

			//if the last index has been filled, break
			if (i == 9)
			{
				break;
			}
		}
	}
}

// This is the implementation of the print function which prints the filled sudoku in eye pleasing way
void Sudoku::print() const 
{


	int num = 9;
	int i = NULL;


	while(i < num) 
	{
	
		if (i % 3 == 0)
		{
			cout << "+-------+-------+-------+" << endl;
		}

		int j = NULL;
		while (j < num)
		{
			if (j % 3 == 0)
			{
				cout << "| ";
			}

			if (grid[i][j] == 0)
			{
				cout << "  ";
			}
			else
			{
				cout << grid[i][j] << " ";
			}
			if (j == 8) cout << "|" << endl; 

			j++;
		}

		i++;
	}

	cout << "+-------+-------+-------+" << endl;
}

// overloading the = operator to be able to copy sudoku objects
Sudoku& Sudoku::operator=(const Sudoku& rhs) {

	if (&rhs != this) {
		int num = 9;
		int i = NULL;
		
		while (i < num)
		{
			int j = NULL;

			// copying the values of another sudoku object
			while (j < num)
			{
				grid[i][j] = rhs.grid[i][j];
				fixedGrid[i][j] = rhs.fixedGrid[i][j];

				j++;
			}
			i++;
		}

	}
	return *this;
}