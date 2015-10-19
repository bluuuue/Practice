#include <iostream>
using namespace std;

void CountBomb(int **matrix, int **bomb, int n, int m)
{
    for (int i = 1; i < n - 1; ++i)
        for (int j = 1; j < m - 1; ++j)
            bomb[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i - 1][j + 1] +
                        matrix[i][j - 1] + matrix[i][j] + matrix[i][j + 1] +
                        matrix[i + 1][j - 1] + matrix[i + 1][j] + matrix[i + 1][j + 1];
    return;
}

int GetTwoSum(int **matrix, int **bomb, int n, int m, int x1, int x2, int y1, int y2)
{
    int nSum = bomb[x1][y1] + bomb[x2][y2];
    int xMin, yMin, xMax, yMax;
    if (x1 < x2)
    {
        xMin = x1;
        yMin = y1;
        xMax = x2;
        yMax = y2;
    }
    else
    {
        xMin = x2;
        yMin = y2;
        xMax = x1;
        yMax = y1;
    }

    if (xMax - xMin >= 3 || abs(y2 - y1) >= 3)
        return nSum;

    int xCount = 3 - (xMax - xMin);
    int xIndex = 1;
    while (xCount--)
    {
        int yCount = 3 - abs(yMax - yMin);
        if (yMax >= yMin)
        {
            int yIndex = 1;
            while (yCount--)
            {
                nSum -= matrix[xMin + xIndex][yMin + yIndex];
                yIndex--;
            }
        }
        else
        {
            int yIndex = -1;
            while (yCount--)
            {
                nSum -= matrix[xMin + xIndex][yMin + yIndex];
                yIndex++;
            }
        }
        xIndex--;
    }
    return nSum;
}

int MaxBombNum(int **matrix, int **bomb, int n, int m)
{
    CountBomb(matrix, bomb, n, m);
    int x1, y1, x2, y2;
    int max = 0;
    for (int i = 1; i < n - 1;)
    {
        for (int j = 1; j < m - 1;)
        {
            x1 = i;
            y1 = j;
            for (x2 = 1; x2 < n - 1; x2++)
                for (y2 = 1; y2 < m - 1; y2++)
                    if (GetTwoSum(matrix, bomb, n, m, x1, x2, y1, y2) > max)
                        max =GetTwoSum(matrix, bomb, n, m, x1, x2, y1, y2); 
        }
    }

    return max;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int **matrix = new int*[n];
    int **bomb = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[m];
        bomb[i] = new int[m];
    }
    
    //initialize the matrix;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = 0;
            bomb[i][j] = 0;
        }

    int x, y;
    while (k--)
    {
        cin >> x >> y;
        ++matrix[x - 1][y - 1];
    }
    cout << MaxBombNum(matrix, bomb, n, m) << endl; 
    return 0;
}
