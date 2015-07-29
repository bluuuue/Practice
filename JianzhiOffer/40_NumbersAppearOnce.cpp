#include <iostream>
using namespace std;

int FindFirstBitIs1(int num)
{
	if (num == 0)
	{
		return -1;
	}

	int nNum = num;
	int nFirstBitIs1 = 0;
	while ( (nNum & 1) == 0 )
	{
		nNum = nNum >> 1;
		++nFirstBitIs1;
	}
	return nFirstBitIs1;
}

bool BitIs1(int num, int nBit)
{
	if (nBit < 0)
	{
		return false;
	}

	int nNum = num;
	while (nBit > 0)
	{
		nNum = nNum >> 1;
		--nBit;
	}

	if (nNum & 1 == 1)
		return true;
	else
		return false;
}

void FindNumsAppearOnce(int data[], int nLength, int *num1, int *num2)
{
	if (data == NULL || nLength <= 1)
	{
		return;
	}

	int nNumsXOR = 0;
	for (int i = 0; i < nLength; ++i)
	{
		nNumsXOR ^= data[i];
	}
	int nFirstBitIs1 = FindFirstBitIs1(nNumsXOR);
	*num1 = 0;
	*num2 = 0;
	for (int i = 0; i < nLength; ++i)
	{
		if (BitIs1(data[i], nFirstBitIs1))
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
	return;
}

int main()
{
	int data[8] = {2, 4, 3, 6, 3, 2, 5, 5};
	int num1, num2;
	FindNumsAppearOnce(data, 8, &num1, &num2);
	cout << num1 << "\t" << num2 << endl;
	return 0;
}
