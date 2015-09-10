#include <iostream>
#include <math.h>
using namespace std;

void NarcissisticNumber(int m, int n)
{
    if (!(m <= n && m >= 100 && n <= 999))
    {
        cout << "no" << endl;
        return ;
    }

    bool bHasFound = false;
    int nHundred, nDecade, nUnit;
    for(int nNum = m; nNum <= n; ++nNum)
    {
        nHundred = nNum / 100;
        nDecade = (nNum - nHundred * 100) / 10;
        nUnit = nNum - nHundred * 100 - nDecade * 10;
        if (nNum == nHundred * nHundred * nHundred + nDecade * nDecade * nDecade + nUnit * nUnit * nUnit)
        {
            bHasFound = true;
            cout << nNum << " ";
        }
    }
    if (!bHasFound)
        cout << "no";
    cout << endl;
}


int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        NarcissisticNumber(m, n);
    }
    return 0;
}

