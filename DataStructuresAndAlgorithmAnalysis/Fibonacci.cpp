#include <iostream>
using namespace std;

int Fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    int nPre = 1;
    int nCur = 1;
    int nCount = 1;
    int nTemp = 0;
    while (++nCount < n)
    {
        nTemp = nCur;
        nCur += nPre;
        nPre = nTemp;
    }

    return nCur;
}

int main()
{
    for (int i = 1; i < 11; i++)
    {
        cout << Fibonacci(i) << endl;
    }

    return 0;
}
