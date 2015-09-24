#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int MinNumber(vector<double> allDevice)
{
    int nCount = 0;
    sort(allDevice.begin(), allDevice.end());//从小到大
    double dLength = 0;
    double dNeedLength = 20;
    auto iter = allDevice.end() - 1;
    while (dLength < dNeedLength && iter >= allDevice.begin() && *iter > 1)
    {
        dLength += 2 * sqrt(*iter * *iter - 1);
        --iter;
        ++nCount;
    }
    double dLack = dNeedLength - dLength;
    while (dLack > 0 && iter >= allDevice.begin())
    {
    }

    return nCount;
}

int main()
{
    int n = 0;
    vector<double> allDevice;
    double temp;
    cin >> n;
    while (n--)
    {
        cin >> temp;
        allDevice.push_back(temp);
    }
    cout << MinNumber(allDevice) << endl;

    return 0;
}
