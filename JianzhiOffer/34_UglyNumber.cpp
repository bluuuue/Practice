#include <iostream>
#include <time.h>

bool IsUglyNumber(const unsigned int num)
{
	unsigned int nNum = num;
	bool bIsUglyNumber = false;
	
	while (nNum % 2 == 0)
	{
		nNum /= 2;
	}
	while (nNum % 3 == 0)
	{
		nNum /= 3;
	}
	while (nNum % 5 == 0)
	{
		nNum /= 5;
	}

	if (nNum == 1)
	{
		bIsUglyNumber = true;
	}

	return bIsUglyNumber;
}

unsigned int GetUglyNumber(int nSeries)
{
	//the low effective way
	if (nSeries <= 0)
	{
		return 0;
	}

	int nCount = 1;
	unsigned int nIndex = 1;
	while (nCount < nSeries)
	{
		if (IsUglyNumber(nIndex))
		{
			++nCount;
		}
		++nIndex;
	}

	return nIndex;
}



int main()
{
	//clock_t tStart1, tStart2, tEnd1, tEnd2;
	int n = 1500;

	//tStart1 = clock();
	std::cout << "The low effective way: " << std::endl;
	std::cout << "  The " << n << "th ugly number is: " << GetUglyNumber(n) << std::endl;
	//tEnd1 = clock();
	//std::cout << "	Time consume: " << tEnd1 - tStart1 << std::endl;

	//tStart2 = clock();
	std::cout << "The high effective way: " << std::endl;

	//tEnd2 = clock();
	//std::cout << "	Time consume: " << tEnd2 - tStart2 << std::endl;
	
	return 0;
}
