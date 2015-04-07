#include <iostream>

bool Find(int *matrix, int row, int col, int number);

int main()
{
	int row = 4;
	int col = 4;
	int matrix[16] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};

	bool found = false;
	for (int num = 0; num < 30; ++num)
	{
		found = Find(matrix, row, col, num);
		std::cout << found << std::endl;
	}
	return 0;
}

bool Find(int *matrix, int row, int col, int number)
{
	bool found = false;

	if (matrix != NULL && row > 0 && col > 0)
	{
		int prow = 0;
		int pcol = col - 1;
		while (prow < row && pcol >= 0)
		{
			int matrix_num = matrix[prow*row + pcol];
			if (number == matrix_num) 
			{
				found = true;
				break;
			}
			else if (number < matrix_num)
			{
				--pcol;
			}
			else if (number > matrix_num)
			{
				++prow;
			}
		}
	}

	return found;
}
