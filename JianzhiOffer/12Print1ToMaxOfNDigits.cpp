#include <iostream>
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

void Print1ToMaxOfNDigits(int n);
{
	if(n <= 0)
	{
		return;
	}
	
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

int main()
{
	Print1ToMaxOfNDigits_1(9);

	return 0;
}
