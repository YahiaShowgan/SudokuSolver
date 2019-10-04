#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "chromosome.h"
#include <algorithm>
#include <random>

namespace Sudoku
{
	using namespace System;
	class Calculations
	{
	public:
		//Roullete wheel selection.
		static int Calculations::randomPickByWeight(std::vector<Chromosome> chromosomes, std::vector<double>weights, double weightSum);
		//mutation of reordering rows, or randomly replacing a number.
		static Chromosome mutate(Chromosome c, std::vector<std::vector<int>> initFilledPlaces);
		static Chromosome crossoverRows(Chromosome c1, Chromosome c2);
		static Chromosome crossoverCols(Chromosome c1, Chromosome c2);
		static Chromosome generateRandomChromosome(std::vector<std::vector<int>> sudokuMatrix);
		static	std::vector<Chromosome> generateRandomPool(std::vector<std::vector<int>> sudokuMatrix, int size);
		static double calcFitness(std::vector<std::vector<int>> sudokuMatrix);
		static bool cheat;
	};
}