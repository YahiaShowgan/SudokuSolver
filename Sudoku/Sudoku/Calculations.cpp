#include "Calculations.h"
namespace Sudoku
{
	bool Calculations::cheat=false;

	//Roullette wheel selection
	int Calculations::randomPickByWeight(std::vector<Chromosome> chromosomes, std::vector<double>weights,double weightSum)
	{
		Random rnd;
		int rand = rnd.Next(0, (int)weightSum);
		int i = 0;
		while ((weights[i] <= rand) && (i<weights.size()))
		{
			i++;
			rand -= weights[i];
		}
		return i;
	}

	Chromosome Calculations::mutate(Chromosome c, std::vector<std::vector<int>> initFilledPlaces)
	{
		Chromosome c2(c);
		Random rand;
		std::vector<std::vector<int>> numsInCol(6, std::vector<int>(6));
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (initFilledPlaces[i][j])
				{
					numsInCol[j][(c.sudokuMatrix[i][j] - 1)] = 1;
				}
			}
		}

		int row = rand.Next(0, 6);
		//20% to randomly change a number in the sudoku.
		if (rand.Next(0, 10) < 2)
		{
			int col = rand.Next(0, 6);
			while (initFilledPlaces[row][col])
				col = rand.Next(0, 6);
			std::vector<int> numsInRow(6);
			std::vector<int> numsInCol(6);
			c2.sudokuMatrix[row][col] = 0;
			for (int i = 0; i < 6; i++)
			{
				if ((c2.sudokuMatrix[row][i] != 0) && (initFilledPlaces[row][i]))
					numsInRow[c2.sudokuMatrix[row][i] - 1] = 1;
				if ((c2.sudokuMatrix[i][col] != 0) && (initFilledPlaces[i][col]))
					numsInCol[c2.sudokuMatrix[i][col] - 1] = 1;
			}
			std::vector<int> rowPossibilities;
			std::vector<int> colPossibilities;
			for (int i = 0; i < 6; i++)
			{
				if (numsInRow[i] == 0)
					rowPossibilities.push_back(i + 1);
				if (numsInCol[i] == 0)
					colPossibilities.push_back(i + 1);
			}

			int numToPlace;
			rowPossibilities.insert(rowPossibilities.end(), colPossibilities.begin(), colPossibilities.end());
			std::random_shuffle(rowPossibilities.begin(), rowPossibilities.end());
			numToPlace = rowPossibilities[0];
			c2.sudokuMatrix[row][col] = numToPlace;
		}
		else //80% reorder a random row
		{
			while (true)

			{
				std::vector<int> rowNums = { 1,2,3,4,5,6 };
				//rowNums.resize(0);
				for (int i = 0; i < 6; i++)
				{
					if (initFilledPlaces[row][i])
						rowNums.erase(std::remove(rowNums.begin(), rowNums.end(), c.sudokuMatrix[row][i]), rowNums.end());
						//rowNums.push_back(c2.sudokuMatrix[row][i]);
				}
				//auto rng = std::default_random_engine{};
				std::random_shuffle(std::begin(rowNums), std::end(rowNums)); //reorder
				int j = 0;
				for (int i = 0; i < 6; i++)
				{
					if (!initFilledPlaces[row][i])
					{
						c2.sudokuMatrix[row][i] = rowNums[j];
						j++;
					}
				}
				int i;
				if (!cheat)
					break;
				for (i = 0; i < 6; i++)
					if ((initFilledPlaces[row][i] == 0) && (numsInCol[i][c2.sudokuMatrix[row][i] - 1] == 1))
						break;
					if (i == 6)
						break;
				
			}
		}
		return c2;
	}

	Chromosome Calculations::crossoverRows(Chromosome c1, Chromosome c2)
	{
		std::vector<std::vector<int>> newMat(6, std::vector<int>(6));
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if ((i < 2) || (i > 3))
					newMat[i][j] = c1.sudokuMatrix[i][j];
				else
					newMat[i][j] = c2.sudokuMatrix[i][j];
			}
		}
		return Chromosome(newMat, calcFitness(newMat));
	}

	Chromosome Calculations::crossoverCols(Chromosome c1, Chromosome c2)
	{
		std::vector<std::vector<int>> newMat(6, std::vector<int>(6));
		for (int j = 0; j < 6; j++)
		{
			for (int i = 0; i < 6; i++)
			{
				if (j < 3)
					newMat[i][j] = c1.sudokuMatrix[i][j];
				else
					newMat[i][j] = c2.sudokuMatrix[i][j];
			}
		}
		return Chromosome(newMat, calcFitness(newMat));
	}

	Chromosome Calculations::generateRandomChromosome(std::vector<std::vector<int>> sudokuMatrix)
	{
		std::vector<std::vector<int>> numbersInRow(6, std::vector<int>(6));//numbersInRow[i][j]=1 means j+1 is in row i
		std::vector<std::vector<int>> initFilledPlaces(6, std::vector<int>(6));
		std::vector<std::vector<int>> numsInCol(6, std::vector<int>(6));
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (sudokuMatrix[i][j] != 0)
				{
					numbersInRow[i][sudokuMatrix[i][j] - 1] = 1;
					numsInCol[j][sudokuMatrix[i][j] - 1] = 1;
					initFilledPlaces[i][j] = 1;
				}
			}
		}
		//now fill every empty spot with a number 1-6 that isn't already in the row.
		for (int i = 0; i < 6; i++)
		{
			std::vector<int> numsMissing;
			for (int num = 0;  num < 6; num++)
			{
				if (numbersInRow[i][num] == 0) //missing
					numsMissing.push_back(num + 1);
			}
			while (true)
			{
				std::random_shuffle(std::begin(numsMissing), std::end(numsMissing));
				int m = 0;
				for (int j = 0; j < 6; j++)
				{
					if (sudokuMatrix[i][j] == 0)
					{
						sudokuMatrix[i][j] = numsMissing[m];
						m++;
					}
				}
				//check if no conflicts with initially filled places.
				int j;
				if (!cheat)
					break;
				for (j = 0; j < 6; j++)
					if ((initFilledPlaces[i][j]==0)&&(numsInCol[j][sudokuMatrix[i][j] - 1] == 1))
						break;
				if (j == 6)
					break;
				else
				{
					for (j = 0; j < 6; j++)
						if (initFilledPlaces[i][j] == 0)
							sudokuMatrix[i][j] = 0;
				}
			}
		}

		Chromosome c(sudokuMatrix, calcFitness(sudokuMatrix));
		return c;
	}

	std::vector<Chromosome> Calculations::generateRandomPool(std::vector<std::vector<int>> sudokuMatrix, int size)
	{
		std::vector<Chromosome> pool;
		for (int i = 0; i < size; i++)
		{
			pool.push_back(generateRandomChromosome(sudokuMatrix));
		}
		std::sort(pool.begin(), pool.end());
		return pool;
	}


	/*
	algorithm to calculate the fitness function, correct solution is 0.
	input: matrix of numbers.
	output: fitness of the matrix.
	*/
	double Calculations::calcFitness(std::vector<std::vector<int>> sudokuMatrix)
	{
		std::vector<double> gi1{ 21,21,21,21,21,21 }; //sum of every row and column should be 21
		std::vector<double> gj1{ 21,21,21,21,21,21 };
		std::vector<double> gi2(6); //product of every row and column should be 720
		std::vector<double> gj2(6);
		std::vector<double> gi3(6); //number of missing elements in every row and column
		std::vector<double> gj3(6);
		double fx;
		for (int i = 0; i < 6; i++)
		{
			double rowProduct = 1, colProduct = 1;
			std::vector<int> numsFoundInRow{ 0,0,0,0,0,0 }; //if changed to 1, means num is found.
			std::vector<int> numsFoundInCol{ 0,0,0,0,0,0 };
			for (int j = 0; j < 6; j++)
			{
				if (sudokuMatrix[i][j] == 0)
					return -1;
				gi1[i] -= sudokuMatrix[i][j]; //sum of row i
				gj1[i] -= sudokuMatrix[j][i]; //sum of column i
				rowProduct *= sudokuMatrix[i][j];
				colProduct *= sudokuMatrix[j][i];
				numsFoundInRow[sudokuMatrix[i][j] - 1] = 1;//num found
				numsFoundInCol[sudokuMatrix[j][i] - 1] = 1;
			}
			gi1[i] = abs(gi1[i]);
			gj1[i] = abs(gj1[i]);
			gi2[i] = abs(720 - rowProduct);
			gj2[i] = abs(720 - colProduct);
			gi3[i] = std::count(numsFoundInRow.begin(), numsFoundInRow.end(), 0);//number of missing elements.
			gj3[i] = std::count(numsFoundInCol.begin(), numsFoundInCol.end(), 0);//number of missing elements.
		}
		fx = std::accumulate(gi1.begin(), gi1.end(), 0.0) + std::accumulate(gj1.begin(), gj1.end(), 0.0);
		fx *= 10;
		for (int i = 0; i < 6; i++)
		{
			fx += sqrt(gi2[i]);
			fx += sqrt(gj2[i]);
		}
		fx += 50 * (std::accumulate(gi3.begin(), gi3.end(), 0.0) + std::accumulate(gj3.begin(), gj3.end(), 0.0));
		//perfect solution should be 0.
		return fx;
	}
}