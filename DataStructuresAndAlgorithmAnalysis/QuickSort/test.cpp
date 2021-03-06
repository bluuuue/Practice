#include "QuickSort.h"
#include <iostream>
using namespace std;

void PrintArray(int *num, int n);

int main() {
    int num[10] = {10, 13, 8, 29, 2, 23, 20, 3, 29, 1};
    cout << "The original array is: " << endl;
    PrintArray(num, 10);
    QuickSort(num, 0, 9);
    cout << "The array after quick sort is: " << endl;
    PrintArray(num, 10);
    return 0;
}

void PrintArray(int *num, int n) {
    if (num == NULL || n <= 0) {
        cout << "Input error." << endl;
        return ;
    }

    for (int i = 0; i < n; ++i) 
        cout << num[i] << " ";
    cout << endl;
}
