//Circulation way
#include <iostream>
#include <math.h>
using namespace std;

int g_nMaxValue = 6;

void InitDicesMatrix(int *data, int nLength)
{
	if (data == NULL || nLength <= 0)
		return;

	for (int i = 0; i < nLength; ++i)
		data[i] = nLength % 6 + 1;
}	

void InitArrayWith0(int *data, int nLength)
{
	if (data == NULL || nLength <= 0)
		return;

	for (int i = 0; i < nLength; ++i)
		data[i] = 0;

	return;
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
	
	int *DicesMatrix = new int[g_nMaxValue * n];
	InitDicesMatrix(DicesMatrix, g_nMaxValue * n);

	int nLength = n * (g_nMaxValue - 1) + 1;
	int *NumberTable = new int[nLength];
	InitArrayWith0(NumberTable, nLength);

	for (int nIndexDices = 1; nIndexDices <= n; ++nIndexDices)
	{
		for (int nIndexNum = 1; nIndexNum <= 6; ++nIndexNum)
		{

	PrintProbability(NumberTable, nLength, n);

	return;
}

int main()
{
	ListDicesProbability(4);

	return 0;
}
