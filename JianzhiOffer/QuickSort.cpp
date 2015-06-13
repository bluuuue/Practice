#include <iostream>
#include "QuickSort.h"

#define RANDOM(a, b) ((rand() % ((b) - (a))) + (a))

void SwapArrayData(int &nA, int &nB)
{
    int nTemp = nA;
    nA = nB;
    nB = nTemp;
}

void PrintArray(int data[], int nLength)
{
    if (data == NULL || nLength <= 0)
    {
        return;
    }

    for (int nIndex = 0; nIndex != nLength; ++nIndex)
    {
        std::cout << data[nIndex] << "\t";
    }

    std::cout << std::endl;

    return ;
}

void SubQuickSort(int data[], int nLength, int start, int end)
{
    if (data == NULL || nLength <= 0 || start < 0 || end >= nLength)
    {
        return ;
    }

    srand((int)time(0));
    int nIndex = RANDOM(start, end);
    int nStartIndex = start;
    int nEndIndex = end;
    while(nStartIndex < nEndIndex)
    {
        if (data[nIndex] > data[nEndIndex] && nIndex < nEndIndex)
        {
            SwapArrayData(data[nIndex], data[nEndIndex]);
            nIndex = nEndIndex;
        }
        if (data[nIndex] < data[nStartIndex] && nIndex > nStartIndex)
        {
            SwapArrayData(data[nIndex], data[nStartIndex]);
            nIndex = nStartIndex;
        }
        if (nStartIndex < nIndex)
        {
            ++nStartIndex;
        }
        if (nEndIndex > nIndex)
        {
            --nEndIndex;
        }
    }

    if (nIndex - start > 1)
    {
        SubQuickSort(data, nIndex - start, start, nIndex - 1);
    } 

    if (end - nIndex > 1)
    {
        SubQuickSort(data, end - nIndex, nIndex + 1, end);
    }
}

void QuickSort(int data[], int nLength)
{
    if (data == NULL || nLength <= 0)
    {
        return ;
    }

    SubQuickSort(data, nLength, 0, nLength - 1);

    return ;
}

/*
int main()
{
    int pIntData[10] = {3, 8, 2, 3, 9, 9, 4, 5, 1, 0};
    PrintArray(pIntData, 10);

    QuickSort(pIntData, 10);

    PrintArray(pIntData, 10);

    return 0;
}
*/
