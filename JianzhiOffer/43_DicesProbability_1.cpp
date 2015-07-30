//Iteration way
#include <iostream>
#include <math.h>
using namespace std;

int g_nMaxValue = 6;

void InitArrayWith0(int *data, int nLength)
{
	if (data == NULL || nLength <= 0)
		return;

	for (int i = 0; i < nLength; ++i)
		data[i] = 0;

	return;
}

void Traverse(int *NumberTable, int &nSum, int nLayer, int n)
{
	//nLayer: the index of dices
	//n: the sum of dices
	if (NumberTable == NULL)
		return;

	for (int i = 1; i <= g_nMaxValue; ++i)
	{
		++nSum;
		//cout << nSum << "in layer " << nLayer << endl;
		if (nLayer == n)
			++NumberTable[nSum - n];
		else
			Traverse(NumberTable, nSum, nLayer + 1, n);
	}
	nSum -= 6;
}

void PrintProbability(int *data, int nLength, int n)
{
	if (data == NULL || nLength < 1)
		return;

	int nSum = pow(g_nMaxValue, n);
	for (int i = 0; i < nLength; ++i)
		cout << (i + n) << ": " << (double)(data[i]) / nSum << endl;

	return;
}

void ListDicesProbability(int n)
{
	if (n < 1)
		return;

	int nLength = n * (g_nMaxValue - 1) + 1;
	int *NumberTable = new int[nLength];
	InitArrayWith0(NumberTable, nLength);

	int nIndex = 0;
	Traverse(NumberTable, nIndex, 1, n); 

	PrintProbability(NumberTable, nLength, n);
	delete[] NumberTable;

	return;
}

int main()
{
	ListDicesProbability(4);

	return 0;
}
