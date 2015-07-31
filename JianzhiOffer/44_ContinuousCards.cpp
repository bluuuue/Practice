#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void *value1, const void *value2)
{
	return *(int*)value1 - *(int*)value2;
}

void PrintArray(int *nums, int nLength)
{
	for (int i = 0; i < nLength; ++i)
		cout << nums[i] << "\t";
	cout << endl;
}

bool IsContinuous(int *numbers, int nLength)
{
	if (numbers == NULL || nLength != 5)
		return false;

	qsort(numbers, nLength, sizeof(int), compare);

	PrintArray(numbers, nLength);

	bool bIsContinuous = false;
	int nJokerCount = 0;
	int nGapCount = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (numbers[i] == 0)
			++nJokerCount;
	}

	if ( nJokerCount > 2)
		return bIsContinuous;

	for (int j = nJokerCount; j < 5; ++j)
	{
		if (j >= 1)
		{
			if ( numbers[j] == numbers[j - 1])
				return bIsContinuous;
			else if (numbers[j - 1] != 0)
				nGapCount += numbers[j] - numbers[j - 1] - 1;
		}
	}

	if (nJokerCount >= nGapCount)
		bIsContinuous = true;

	return bIsContinuous;
}

int main()
{
	int nums[5] = {0, 7, 9, 4, 5};
	cout << IsContinuous(nums, 5) << endl;

	return 0;
}
