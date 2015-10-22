#include <iostream>
using namespace std;

void quicksort(int *, int, int);
void print(int *, int);

int main()
{
    int num[8] = {2, 34, 1, 325, 3298, 2, 23, 9};
    quicksort(num , 0, 7);
    print(num, 8);
	return 0;
}

void quicksort(int *num, int left, int right) {
    if (num == NULL || left < 0 || left >= right)
        return;
    int start = left, end = right;
    int temp = num[start];
    while (start < end) {
        while (num[end] > temp)
            --end;
        if (start < end)
            num[start] = num[end];
        else
            break;

        while (num[start] <= temp)
            ++start;
        if(start < end)
            num[end] = num[start];
        else
            break;
    }
    num[end] = temp;
    quicksort(num, left, end - 1);
    quicksort(num, end + 1, right);
}

void print(int *num, int n) {
    for (int i = 0; i < n; ++i) {
        cout << num[i] << " ";
    }
    cout << endl;
}
