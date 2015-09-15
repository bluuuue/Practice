#include <iostream>
#include <algorithm>
using namespace std;

int GetMax(int n, int m, int k)
{
    int *array = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }

    //对所有可能进行排序，取前k个结果相加
    for (int i = 0; i < n - m + 1; ++i)
    {
        for (int ii = 0; ii < n - m + 1 - i;)
        {
            int gap = 0;
            int nOneSum = 0;
            for (int j = 0; j < m; ++j)
            {
                nOneSum += array[i + ii + j];
            }
            ii = ii + j;
        }


        {
        }
    }

    int nMaxSum = 0;
    for (int i = n - m; i > n - m - k; --i)
    {
        nMaxSum += allPossibility[i];
    }
    delete array;
    array = NULL;
    return nMaxSum;
}

int main()
{
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        cout << GetMax(n, m, k) << endl;
    }
    return 0;
}
