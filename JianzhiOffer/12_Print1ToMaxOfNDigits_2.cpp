#include <iostream>
#include <cstring>
#include <stdio.h>

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

void Print1ToMaxOfNDigitsRecursively(char *number, int length, int index)
{
	if(index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for(int i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
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

	for(int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}

	delete []number;
}

int main()
{
	Print1ToMaxOfNDigits(13);

	std::cout << std::endl;
	return 0;
}
