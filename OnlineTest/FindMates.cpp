#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Find(int **p, int n)
{
	if (p == NULL || n <= 0)
		return 0;
	
	vector<int> allMates;
	allMates.push_back(0);
	int index = 0;
	while (index < allMates.size())
	{
		for (int i = 0; i < n; ++i)
		{
			if (p[i][allMates[index]] == 1 && find(allMates.begin(), allMates.end(), i) == allMates.end())
			{
				allMates.push_back(i);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (p[allMates[index]][i] == 1 && find(allMates.begin(), allMates.end(), i) == allMates.end())
			{
				allMates.push_back(i);
			}
		}
		++index;
	}

	return allMates.size() - 1;
}

int main()
{
	int n, m;
	int nA, nB;
	while (1)
	{
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        int **p;
        p = new int*[n];
        for (int i = 0; i != n; ++i)
        {
            p[i] = new int[n];
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                p[i][j] = 0;
            }
        }

        int nMin, nMax;
		int loop = m;
		while (loop--)
		{
			cin >> nA >> nB;
			if (nA > nB)
			{
				nMin = nB;
				nMax = nA;
			}
			else
			{
				nMin = nA;
				nMax = nB;
			}
			p[nMin - 1][nMax - 1] = 1;
		}
		cout << Find(p, n) << endl;
	}
	return 0;
}
