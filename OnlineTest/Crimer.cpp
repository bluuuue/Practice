#include <iostream>
using namespace std;

int GetChoices(int n, int t, int c)
{
    int *criminalValue = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> criminalValue[i];
    }

    int nPossibility = 0;
    for (int i = 0; i < n - c + 1; ++i)
    {
        int nCountCriminalValue = criminalValue[i];
        for (int j = 1; j < c; ++j)
        {
            nCountCriminalValue += criminalValue[i + j];
            if (nCountCriminalValue > t)
                break;
        }
        if (nCountCriminalValue <= t)
        {
            ++nPossibility;
        }
    }
    return nPossibility;
}

int main()
{
    int n, t, c;
    while(cin >> n >> t >> c)
    {
        cout << GetChoices(n, t, c) << endl;
    }

    return 0;
}
