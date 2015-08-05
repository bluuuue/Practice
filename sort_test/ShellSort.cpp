#include <iostream>
using namespace std;

void PrintArray(int *nums, int nLength)
{
    if (nums == NULL || nLength <= 0)
        return;

    for (int i = 0; i < nLength; ++i)
        cout << nums[i] << "\t";
    cout << endl;
    return;
}

void ShellSort(int *nums, int nLength)
{
    if (nums == NULL || nLength < 1)
        return ;

    PrintArray(nums, nLength);

    for (int nIncrement = nLength / 2; nIncrement > 0; nIncrement /= 2)
    {
        cout << "Increment: " << nIncrement << endl;
        for (int i = nIncrement; i < nLength; ++i)
        {
            int nTemp = nums[i];
            cout << "i: " << i << "\t" << "temp: " << nTemp << endl;
            int j;
            for (j = i; j >= nIncrement; j -= nIncrement)
            {
                if (nTemp < nums[j - nIncrement])
                    nums[j] = nums[j - nIncrement];
                else 
                    break;
            }
            nums[j] = nTemp;
            PrintArray(nums, nLength);
        }
    }
}

int main()
{
    int numbers[13] = {81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};
    ShellSort(numbers, 13);

    return 0;
}
