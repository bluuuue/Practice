#include <iostream>

int GetNumberOf1(int n)
{
	if (n <= 0)
	{
		return 0;
	}

	int nDigits = 1;
	int nTemp = n;
	while (nTemp > 10)
	{
		++nDigits;
		nTemp = nTemp / 10;
	}

	return nDigits;
}

int main()
{
	std::cout << "The number of 1 is: " << GetNumberOf1(12345) << std::endl;

	return 0;
}
