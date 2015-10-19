#include <iostream>
#include <vector>
using namespace std;

int SearchTreasure(vector<vector<int> > grid)
{
    int nCount = 0;


    if (nCount > 1000000007)
        nCount -= 1000000007;
    return 0;
}

int main()
{
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

    cout << SearchTreasure(grid);

    return 0;
}
