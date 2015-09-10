#include <iostream>
#include <math.h>
using namespace std;

double GetSum(int n, int m)
{
    if(m <= 0)
        return 0;
    double dSum = 0;
    double dN = n;
    while(m)
    {
        dSum += dN;
        dN = sqrt(dN);
        m¡ª;`
    }
    return dSum;
}

int main()
{
    int n, m;
    double dSum;
    while(cin >> n >> m)
    {
        dSum = GetSum(n, m);
        printf("%.2lf\n", dSum);
    }
    return 0;
}

