#include <iostream>
#include "GeneticAlgorithm.h"

using namespace std;

int main(int argc, char* argv[]) {

	int size, num;

	// first command line is the population size 
	size = atoi(argv[1]);

	// second command line is the generation number
	num = atoi(argv[2]);

	//Asking for a text file
	string textFile;



	cout << "Enter the filename which has the sudoku object numbers. Example(sudoku.txt): ";
	cin >> textFile;

	cout << "The population size entered: " << size << endl;
	cout << "The number of generations entered: " << num << endl << endl;
	// run the genetic algorithm given the values
	GeneticAlgorithm g(size, num, textFile);

}