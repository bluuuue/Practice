#include <iostream>
#include <vector>
using namespace std;

int GetGCD(int a, int b)
{
    int min = a < b ? a : b;
    for (int i = min; i >= 1; --i)
    {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

int GetFinalPower(int *nums, int n, int a)
{
    if (nums == NULL || n <= 0)
        return 0;
    int nFinalPower = a;
    for (int i = 0; i < n; ++i)
    {
        if (nFinalPower >= nums[i])
            nFinalPower += nums[i];
        else
            nFinalPower += GetGCD(nFinalPower, nums[i]);
    }
    return nFinalPower;
}

int main()
{
    int n, a;
    vector<int> result;
    while ( cin >> n >> a)
    {
        int *nums = new int[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        result.push_back(GetFinalPower(nums, n, a));
    }
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << endl;

    return 0;
}
