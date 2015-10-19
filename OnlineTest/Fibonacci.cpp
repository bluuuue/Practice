#include <iostream>
#include <vector>
using namespace std;

int Fibonacci(int n)
{
    if(n <= 2)
        return 1;
    int A = 1;
    int B = 1;
    int C;
    while(n > 2)
    {
        C = B;
        B = A + B;
        A = C;
        --n;
    }
    return B;
}

int SubSequenceCount(vector<int> nums)
{
    int AllSum = 0;
    int size = nums.size();
    for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ++it)
    {
        if (*it < *(it - 1))
            nums.erase(it);
    }
    int n = nums.size();

    //计算1的组合一共有多少组
    int num1 = 0;
    int Count1 = 0;
    for (int i = 0; i < n ; ++i)
    {
        if (nums[i] == 1)
            num1++;
    }
    if (num1 == 0)
        return 0;
    else if (num1 == 1)
        return 1;
    else
        Count1 = (num1 - 1) * num1 / 2;
    AllSum += (Count1 + num1);
    while (AllSum > 1000000007)
        AllSum -= 1000000007;

    int index = 2;
    int LastPossibility = (num1 - 1) * num1 / 2;
    while (Fibonacci(index) <= nums[n - 1])
    {
        int nCount = 0;
        int fiboNum = Fibonacci(index);
        for (int i = 0; i < n ; ++i)
        {
            if (nums[i] == fiboNum)
                nCount++;
            else if (nums[i] > fiboNum)
                break;
        }
        if (nCount == 0)
            return AllSum;

        AllSum += LastPossibility * nCount;
        while (AllSum > 1000000007)
            AllSum -= 1000000007;
        LastPossibility = nCount * LastPossibility;
        ++index;
    }
    return AllSum;
}

int main()
{
    int n;
    cin >> n;
    int num;
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        nums.push_back(num);
    }
    cout << SubSequenceCount(nums) << endl;

    return 0;
}
