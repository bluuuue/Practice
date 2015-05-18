#include <iostream>

void InitMatrix(int numbers[][4], int row, int col)
{
	for(int nRowSeries = 0; nRowSeries < row; ++nRowSeries)
	{
		for(int nColSeries = 0; nColSeries < col; ++nColSeries)
		{
			*((int*)(numbers) + nRowSeries * col + nColSeries) = col * nRowSeries + nColSeries + 1;
		}
	}
}

void PrintMatrix(int **numbers, int row, int col)
{
	for(int nRowSeries = 0; nRowSeries < row; ++nRowSeries)
	{
		for(int nColSeries = 0; nColSeries < col; ++nColSeries)
		{
			std::cout << *((int*)(numbers) + nRowSeries * col + nColSeries) << std::endl;
		}
	}
}

void PrintMatrixInCircle(int **numbers, int row, int col)
{
}

void PrintMatrixClockwisely(int **numbers, int row, int col)
{
	if(numbers == NULL)
	{
		return;
	}

	int start = 0;
	while(start * 2 < row && start * 2 < col)
	{

	}
}

int main()
{
	int numbers[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	InitMatrix(numbers, 3, 4);
	PrintMatrix((int**)numbers, 3, 4);

	int numbers2[5][4] = {0};
	InitMatrix(numbers2, 5, 4);
	PrintMatrix((int**)numbers2, 5, 4);

	return 0;
}

