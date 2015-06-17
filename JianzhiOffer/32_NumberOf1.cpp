#include "IntToStr.h"
#include <iostream>
#include <string>
#include <math.h>

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
		//Warning: convert double to int must add 0.5
		int nTemp1 = static_cast<int>(pow(10, nDigits - 1 - nIndex) + 0.5); 
		int nTemp2 = static_cast<int>(pow(10, nDigits - nIndex) + 0.5); 
		if (str[nIndex] > '1')
		{
			nNumberOf1 += nTemp1 * (static_cast<int>(n / nTemp2) + 1);
		}
		else if (str[nIndex] == '1')
		{
			nNumberOf1 += nTemp1 * static_cast<int>(n / nTemp2);
			nNumberOf1 += static_cast<int>(n % nTemp1) + 1;
		}
		else if (str[nIndex] == '0')
		{
			nNumberOf1 += nTemp1 * static_cast<int>(n / nTemp2);
		}
	}

	return nNumberOf1;
}

int main()
{
	std::cout << "The number of 1 is: " << GetNumberOf1(21345) << std::endl;

	return 0;
}
