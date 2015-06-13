#include <iostream>
#include "QuickSort.h"

void GetKLeastNumbers(int *numbers, int nLength, int *output, int k)
{
    if (numbers == NULL || nLength <= 0 || k <= 0 || k > nLength)
    {
        return ;
    }

    QuickSort(numbers, nLength);

    for (int nIndex = 0; nIndex != k; ++nIndex)
    {
        output[nIndex] = numbers[nIndex];
    }
}

int main()
{
    int data[8] = {19, 32, 33, 13, 5, 11, 3, 0};
    int kNumbers[4] = {};
    GetKLeastNumbers(data, 8, kNumbers, 4);
    PrintArray(kNumbers, 4);


    return 0;
}
