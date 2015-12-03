#include "QuickSort.h"
#include <iostream>
using namespace std;

void QuickSort(int *num, int nLeft, int nRight) {
    if (num == NULL || nLeft >= nRight)
        return;

    int pA = nLeft, pB = nRight;
    int nTemp = num[nLeft];
    while (pA < pB) {
        while (pA < pB && num[pB] >= nTemp)
            --pB;
        if (pA < pB)
            num[pA] = num[pB];
        else 
            break;
        while (pA < pB && num[pA] < nTemp)
            ++pA;
        if (pA < pB)
            num[pB] = num[pA];
//        else 
//            break;
    }
    num[pB] = nTemp;
    QuickSort(num, nLeft, pB - 1);
    QuickSort(num, pB + 1, nRight);
}
