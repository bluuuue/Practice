#include <iostream>

void PrintArray(int array[], int length)
{
	if(array == NULL || length <= 0)
	{
		return;
	}

	std::cout << "Array: " << std::endl;
	for(int i = 0; i < length; ++i)
	{
		std::cout << array[i] << std::endl;
	}
	std::cout << std::endl;
}

void ReorderOddEven(int *pData, unsigned int length)
{
	if(pData == NULL || length <= 0)
	{
		return;
	}

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while(pBegin < pEnd)
	{
		while( !((*pBegin & 0x1) == 0) )
		{
			++pBegin;
		}

		while( (*pEnd & 0x1) == 0)
		{
			--pEnd;
		}

		if(pBegin < pEnd)
		{
			*pBegin = *pBegin ^ *pEnd;
			*pEnd = *pBegin ^ *pEnd;
			*pBegin = *pBegin ^ *pEnd;
		}
	}
}

int main()
{
	int nLength = 11;
	int *aArray = new int[nLength];
	for(int i = 0; i < nLength; ++i)
	{
		aArray[i] = i + 1;
	}
	PrintArray(aArray, nLength);

	ReorderOddEven(aArray, nLength);
	PrintArray(aArray, nLength);

	return 0;
}
