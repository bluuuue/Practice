#include <iostream>
#include <cstring>
#include <stdio.h>

void Print1ToMaxOfNDigits_1(int n)
{
	int number = 1;
	int i = 0;
	while(i++ < n)
	{
		number *= 10;
	}

	for(i = 1; i < number; ++i)
	{
		printf("%d\t", i);
	}
}

bool Increment(char *number)
{
	bool bIsOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	std::cout << "nLength: " << nLength << std::endl;
	for(int i = nLength - 1; i >= 0; --i)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if(i == nLength
	}

	bIsOverflow = true;
	return bIsOverflow;
}

void PrintNumber(char *number)
{
}

void Print1ToMaxOfNDigits(int n)
{
	if(n <= 0)
	{
		return;
	}
	
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while(!Increment(number))
	{
		PrintNumber(number);
	}

	delete []number;
}

int main()
{
	Print1ToMaxOfNDigits_1(4);
	Print1ToMaxOfNDigits(4);

	return 0;
}
