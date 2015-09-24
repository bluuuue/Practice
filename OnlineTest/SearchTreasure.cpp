#include <iostream>
#include <vector>
using namespace std;
int nCount = 0;
//未解决

void Traverse(vector<vector<int> > grid, int i, int j, int k, int nSum, int nMax)
{
    if (nSum >= k)
        return;

    if (i > grid.size() || j > grid[0].size())
        return;

    if (grid[i][j] <= nMax)
    {
        Traverse(grid, i + 1, j, k, nSum, nMax);
        Traverse(grid, i, j + 1, k, nSum, nMax);
    }
    else
    {
        nSum++;
        if (nSum >= k)
        {
            nMax = grid[i][j];
            nCount++;
            if (nCount > 1000000007)
                nCount -= 1000000007;
        }
        nSum--;
        Traverse(grid, i + 1, j, k, nSum, nMax);
        Traverse(grid, i, j + 1, k, nSum, nMax);
    }

}

int SearchTreasure(vector<vector<int> > grid, int k)
{
    int n = grid.size();
    int m = 0;
    if (n > 0)
        m = grid[0].size();
    if (k > n + m - 1)
        return 0;

    int nSum = 0;
    int nMax = 0;
    int i = 0;
    int j = 0;
    Traverse(grid, i, j, k, nSum, nMax);

    return nCount;
}

int main()
{
    int num = 1000000007;
    cout << num << endl;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> row;
    vector<vector<int> > grid;
    int temp;
    while (n--)
    {
        int nColCount = m;
        while (nColCount--)
        {
            cin >> temp;
            row.push_back(temp);
        }
        grid.push_back(row);
        row.clear();
    }

    cout << SearchTreasure(grid, k) << endl;

    return 0;
}
