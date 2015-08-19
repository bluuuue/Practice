#include <iostream>
using namespace std;

class A;
A* array[2];

class A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {return 0;}
};

class B: public A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return array[!!n]->Sum(n - 1) + n;
    }
};

int SumSolution(unsigned int n)
{
    A a;
    B b;
    array[0] = &a;
    array[1] = &b;

    int value = array[1]->Sum(n);

    return value;
}

int main()
{
    cout << SumSolution(100) << endl;

	return 0;
}
