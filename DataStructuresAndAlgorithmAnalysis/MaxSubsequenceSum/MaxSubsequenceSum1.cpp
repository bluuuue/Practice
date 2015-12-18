#include <iostream>
using namespace std;

int Max3(const int &a, const int &b, const int &c)
{
    int d = (a > b ? a : b); 
    return d > c ? d : c;
}

/*
*use divide&conquer to solve max subsequence sum problem
*/
int MaxSubSum(const int arr[], int left, int right)
{
    int maxLeftSum = 0;
    int maxRightSum = 0;
    int maxLeftBorderSum = 0;
    int maxRightBorderSum = 0;
    int leftBorderSum = 0;
    int rightBorderSum = 0;
    int center; 
    int i = 0;

    if (left == right)
    {
        if (arr[left] > 0)
            return arr[left];
        else
            return 0;
    }

    center = (left + right) / 2;
    maxLeftSum = MaxSubSum(arr, left, center);
    maxRightSum = MaxSubSum(arr, center + 1, right);

    for (i = center; i >= left; i--)
    {
        leftBorderSum += arr[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    for (i = center + 1; i <= right; i++)
    {
        rightBorderSum += arr[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return Max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int MaxSubsequenceSum(const int arr[], int n)
{
    return MaxSubSum(arr, 0, n - 1);
}

int main()
{
    int arr[] = {4, -3, 5, -2, -1, 2, 6, -2};
    cout << MaxSubsequenceSum(arr, 8) << endl;
    return 0;
}
