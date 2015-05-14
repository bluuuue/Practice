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
	for(int i = nLength - 1; i >= 0; --i)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if(i == nLength - 1)
		{
			++nSum;
		}

		if(nSum >= 10)
		{
			if(i == 0)
			{
				bIsOverflow = true;
			}
			else
			{
				nTakeOver = 1;
				nSum -= 10;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}

	return bIsOverflow;
}

void PrintNumber(char *number)
{
	bool bIsBeginning0 = true;
	int nLength = strlen(number);

	for(int i = 0; i < nLength; ++i)
	{
		if(bIsBeginning0 && number[i] != '0')
		{
			bIsBeginning0 = false;
		}

		if(!bIsBeginning0)
		{
			printf("%c", number[i]);
		}
	}
	printf("\t");
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
	//Print1ToMaxOfNDigits_1(4);
	Print1ToMaxOfNDigits(17);

	return 0;
}
