#include <iostream>
using namespace std;

/*
*online algorithm 
*/
int MaxSubsequenceSum(const int arr[], int n)
{
    int currSum = 0;
    int maxSum = 0;
    int i = 0;

    for (i = 0; i < n; i++)
    {
        currSum += arr[i];

        if (currSum > maxSum)
            maxSum = currSum;
        else if (currSum < 0)
            currSum = 0;
    }

    return maxSum;
}

int main()
{
    int arr[] = {4, -3, 5, -2, -1, 2, 6, -2};
    cout << MaxSubsequenceSum(arr, 8) << endl;
    return 0;
}
