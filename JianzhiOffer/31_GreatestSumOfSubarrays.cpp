#include <iostream>

bool gInvalidInput = false;

int GetGreatestSumOfSubarrays(int data[], int nLength)
{
    if (data == NULL || nLength <= 0)
    {
        gInvalidInput = true;
        return -1;
    }

    gInvalidInput = false;

    int nCurSum = 0;
    int nGreatestSum = 0x80000000;

    for (int nIndex = 0; nIndex != nLength; ++nIndex)
    {
        if (nCurSum < 0)
        {
            nCurSum = data[nIndex];
        }
        else
        {
            nCurSum += data[nIndex];
            if (nCurSum > nGreatestSum)
            {
                nGreatestSum = nCurSum;
            }
        }
    }

    return nGreatestSum;
}

int main()
{
    int data[8] = {1, -2, 3, 10, -4, 7, 2, -5};
    std::cout << "The greatest sum of subarrays is: " << GetGreatestSumOfSubarrays(data, 8) << std::endl;

    int data2[3] = {-1, -3, -1};
    std::cout << "The greatest sum of subarrays is: " << GetGreatestSumOfSubarrays(data2, 3) << std::endl;

    return 0;
}

