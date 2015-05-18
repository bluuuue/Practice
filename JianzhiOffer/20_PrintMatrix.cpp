#include <iostream>

void InitMatrix(int **numbers, int row, int col)
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

void PrintMatrixInCircle(int **numbers, int row, int col, int start)
{
	int nEndCol = col - start - 1;
	int nEndRow = row - start - 1;

	for(int nColSeries = start; nColSeries <= nEndCol; ++nColSeries)
	{
		std::cout << *((int*)(numbers) + col * start + nColSeries) << "\t";
	}

	if(start < nEndRow)
	{
		for (int nRowSeries = start + 1; nRowSeries <= nEndRow; ++nRowSeries)
		{
			std::cout << *((int*)(numbers) + nRowSeries * col + nEndCol) << "\t";
		}
	}

	if (start < nEndRow && start < nEndCol)
	{
		for (int nColSeries = nEndCol - 1; nColSeries >= start; --nColSeries)
		{
			std::cout << *((int*)(numbers) + nEndRow * col + nColSeries) << "\t";
		}
	}

	if (start < nEndRow - 1 && start < nEndCol)
	{
		for (int nRowSeries = nEndRow - 1; nRowSeries >= start + 1; --nRowSeries)
		{
			std::cout << *((int*)(numbers) + nRowSeries * col + start) << "\t";
		}
	}
}

void PrintMatrixClockwisely(int **numbers, int row, int col)
{
	if(numbers == NULL || row <= 0 || col <= 0)
	{
		return;
	}

	int start = 0;
	while(start * 2 < row && start * 2 < col)
	{
		PrintMatrixInCircle(numbers, row, col, start);
		++start;
	}
	std::cout << std::endl;
}

int main()
{
	int numbers2[5][7] = {0};
	InitMatrix((int**)numbers2, 5, 7);
	PrintMatrix((int**)numbers2, 5, 7);
	std::cout << std::endl;

	PrintMatrixClockwisely((int**)numbers2, 5, 7);

	return 0;
}
