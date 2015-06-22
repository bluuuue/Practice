#include <iostream>
#include <time.h>

bool IsUglyNumber(const unsigned int num)
{
	unsigned int nNum = num;
	bool bIsUglyNumber = false;
    if (nNum == 0)
    {
        return bIsUglyNumber;
    }
	
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

unsigned int GetUglyNumberLowEffective(int nSeries)
{
	//the low effective way
	if (nSeries <= 0)
	{
		return 0;
	}

	int nCount = 0;
	unsigned int nIndex = 0;
	while (nCount < nSeries)
	{
		++nIndex;
		if (IsUglyNumber(nIndex))
		{
			++nCount;
		}
	}

	return nIndex;
}

int MinOfThree(int nNum1, int nNum2, int nNum3)
{
    return (nNum1 < nNum2) ? ((nNum1 < nNum3) ? nNum1 : nNum3) : ((nNum2 < nNum3) ? nNum2 : nNum3);
}

unsigned int GetUglyNumberHighEffective(int nSeries)
{
    if (nSeries <= 0)
    {
        return 0;
    }
    
    int *pUglyNubmer = new int[nSeries];
    int nIndex = 0;
    pUglyNubmer[nIndex] = 1;

    int *pNumberMultiply2 = pUglyNubmer;
    int *pNumberMultiply3 = pUglyNubmer;
    int *pNumberMultiply5 = pUglyNubmer;

    for (nIndex = 1; nIndex != nSeries; ++nIndex)
    {
        pUglyNubmer[nIndex] = MinOfThree(*pNumberMultiply2 * 2, *pNumberMultiply3 * 3, *pNumberMultiply5 * 5);

        while (*pNumberMultiply2 * 2 <= pUglyNubmer[nIndex])
        {
            ++pNumberMultiply2;
        }

        while (*pNumberMultiply3 * 3 <= pUglyNubmer[nIndex])
        {
            ++pNumberMultiply3;
        }

        while (*pNumberMultiply5 * 5 <= pUglyNubmer[nIndex])
        {
            ++pNumberMultiply5;
        }
    }

    int nUglyNumber = pUglyNubmer[nSeries - 1];
    delete[] pUglyNubmer;

    return nUglyNumber;
}

int main()
{
	clock_t tStart1, tStart2, tEnd1, tEnd2;
	int n = 1500;

	tStart1 = clock();
	std::cout << "The low effective way: " << std::endl;
	//std::cout << "  The " << n << "th ugly number is: " << GetUglyNumberLowEffective(n) << std::endl;
	tEnd1 = clock();
	std::cout << "	Time consume: " << tEnd1 - tStart1 << std::endl;

	tStart2 = clock();
	std::cout << "The high effective way: " << std::endl;
	std::cout << "  The " << n << "th ugly number is: " << GetUglyNumberHighEffective(n) << std::endl;
	tEnd2 = clock();
	std::cout << "	Time consume: " << tEnd2 - tStart2 << std::endl;
	
	return 0;
}
