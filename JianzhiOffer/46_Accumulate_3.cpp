#include <iostream>
using namespace std;

typedef unsigned int (*fun)(unsigned int);

unsigned int SolutionTeminator(unsigned int n)
{
    return 0;
}

unsigned int SumSolution(unsigned int n)
{
    static fun f[2] = {SolutionTeminator, SumSolution};
    return n + f[!!n](n - 1);
}

int main()
{
    cout << SumSolution(100) << endl;
     
    return 0;
}
