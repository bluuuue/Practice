#include "HeapSort.h"
#include <iostream>
using namespace std;

void swap(int a, int b) {
    if (a == b) return;
    a ^= b;
    b ^= a;
    a ^= b;
}

void MinHeapFixDown(int *num, int i, int n) {
    int j = 2 * i + 1;
    int temp = num[i];
    while (j < n) {
        if (j + 1 < n && num[j] > num [j + 1])
            ++j;
        if (num[j] >= temp)
            break;
        num[i] = num[j];
        i = j;
        j = 2 * i + 1;
    }
    num[i] = temp;
}

int HeapSort(int *num, int n) {
    if (num == NULL || n <= 0) {
        cout << "Input Error." << endl;
        return -1;
    }

    //堆化数组
    for (int i = n / 2 - 1; i >= 0; --i)
        MinHeapFixDown(num, i, n);

    //堆排序
    for (int i = n - 1; i > 0; --i) {
        swap(num[i], num[0]);
        MinHeapFixDown(num, 0, i);
    }
    return 0;
}
