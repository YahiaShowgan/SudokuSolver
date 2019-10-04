#pragma once
#include <vector>

class Chromosome
{
public:
	//The sudoku solution
	std::vector<std::vector<int>> sudokuMatrix;
	//The solution's fitness
	double fitness;
	//how many generations gene has been alive
	int age;

	//Constructor
	Chromosome(std::vector<std::vector<int>> sudokuMatrix, double fitness)
	{
		this->sudokuMatrix = sudokuMatrix;
		this->fitness = fitness;
		this->age = 0;
	}
	
	//Copy Constructor
	Chromosome(const Chromosome &c2)
	{
		this->fitness = c2.fitness;
		this->sudokuMatrix = c2.sudokuMatrix;
		this->age = c2.age;
	}

	//Comparison operator by fitness
	bool operator < (const Chromosome& c) const
	{
		return (fitness < c.fitness);
	}
};
