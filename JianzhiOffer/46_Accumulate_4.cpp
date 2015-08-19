#include <iostream>
using namespace std;

template <unsigned int n> struct Sum
{
    enum Value {N = Sum<n - 1>::N + n};
};

template <> struct Sum<1>
{
    enum Value {N = 1};
};

int main()
{
    //n为0时出错
    cout << Sum<100>::N << endl;

    return 0;
}
