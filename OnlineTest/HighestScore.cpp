#include <iostream>
using namespace std;

void Question(int *num, int nLength)
{
    if (num == NULL || nLength <= 0)
        return;

    int nStart = 0;
    int nEnd = 0;
    cin >> nStart >> nEnd;
    if(nStart > nEnd)
    {
        nStart += nEnd;
        nEnd = nStart - nEnd;
        nStart -= nEnd;
    }
    int nScore = 0;
    for (int i = nStart; i <= nEnd; ++i)
        if (num[i] > nScore)
            nScore = num[i];
    cout << nScore << endl;
}

void Update(int *num, int nLength)
{
    if (num == NULL || nLength <= 0)
        return;

    int nSeries = 0;
    int nScore = 0;
    cin >> nSeries >> nScore;
    num[nSeries] = nScore;
}

int main()
{
    int N = 0;
    int M = 0;
    cin >> N >> M;
    if (N <= 0 || M <= 0)
        return -1;

    int *score = new int[N + 1];
    for(int i = 1; i < N + 1; ++i)
    {
        cin >> score[i];
    }

    char C;
    while(M--)
    {
        cin >> C;
        if (C == 'Q')
            Question(score, N + 1); 
        else if (C == 'U')
            Update(score, N + 1);
        else
            return -1;
    }

    return 0;
}
