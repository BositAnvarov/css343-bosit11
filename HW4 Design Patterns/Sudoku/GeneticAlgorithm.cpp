#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int size, int num, string fileName)
{

	// reading the given text file 
	// making the sudoku from the given characters in the file
	Sudoku object;
	ifstream file(fileName);
	object.read(file);



	// adding the sudoku object and given size 
	// to the new SudokuPopulation
	SudokuPopulation population(size, object);
	file.close();


	// Using a loop to iterate each generation 
	int i = NULL;
	while (i < num)
	{
		// if the sudoku's fitness level reaches 0, stop the loop
		// since best fit sudoku has been found
		if (population.bestFitness() == 0)
		{
			break;
		}

		// print sudoku result after each generation 
		if (i < num)
		{
			cout << "Best fitness number of generation: " << i + 1 << endl;
			population.bestIndividual().print();
			// display the fitness rank number
			cout << "Fitness number: " << population.bestFitness() << endl << endl;
		}

		population.cull();
		population.newGeneration(size);

		i++;

	}

	// Display information about the sudoku with the best fitness number, 0 being the best 
	cout << "Sudoku with the best fit rank after " << num << " generations: " << endl;
	population.bestIndividual().print();
	// display the fitness rank number
	cout << "Fitness number: " << population.bestFitness() << endl;


}
