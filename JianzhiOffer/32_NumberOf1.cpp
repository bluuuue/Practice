#include "IntToStr.h"
#include <iostream>
#include <string>
#include <math>

int GetNumberOf1(const int n)
{
	if (n <= 0)
	{
		return 0;
	}

    std::string str;
    ConvertIntToString(n, str);

	int nDigits = str.size();

	int nNumberOf1 = 0;
	for (int nIndex = 0; nIndex != nDigits; ++nIndex)
	{
		if (str[nIndex] > '1')
		{
			nNumberOf1 += pow(10, nDigits - 1 - nIndex);
		}
		else if (str[nIndex] == '1')
		{



	return nDigits;
}

int main()
{
	std::cout << "The number of 1 is: " << GetNumberOf1(12345) << std::endl;

	return 0;
}
