#include "MergeSort.h"
#include <iostream>
using namespace std;

void Merge(int *num, int *numTemp, int nLeft, int nCenter, int nRight) {
    int pA = nLeft;
    int pB = nCenter;
    int pC = nLeft;
    while (pA < nCenter && pB <= nRight) {
        if (num[pA] < num[pB]) 
            numTemp[pC++] = num[pA++];
        else 
            numTemp[pC++] = num[pB++];
    }
    while (pA < nCenter)
        numTemp[pC++] = num[pA++];
    while (pB <= nRight)
        numTemp[pC++] = num[pB++];
    for (int i = nLeft; i <= nRight; ++i)
        num[i] = numTemp[i];
}

void MSort(int *num, int *numTemp, int nLeft, int nRight) {
    if (num == NULL || numTemp == NULL || nLeft >= nRight) 
        return ;

    int nCenter = (nLeft + nRight) / 2;
    MSort(num, numTemp, nLeft, nCenter);
    MSort(num, numTemp, nCenter + 1, nRight);
    Merge(num, numTemp, nLeft, nCenter + 1, nRight);
}

void MergeSort(int *num, int n) {
    if (num == NULL || n <= 0) {
        cout << "Input error." << endl;
        return ;
    }
    int *numTemp = new int[n];
    MSort(num, numTemp, 0, n - 1);
}



