#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define swap(a, b) (a = a^b, b = a^b, a = a^b)

struct AAA {
    long a;
    long b;
    short rgb[3];
    float d;
};

class A {
    public:
static int a;
static int fun();
    int fun2()
    {
        fun();
        return 0;
    }
};

int A::a = 1;
int A::fun()
{
    cout << "1" << endl;
    return 1;
}

class B:public A{
};

int main()
{
    cout << "\"" << endl;
    int i = 0x80000000;
    cout << i << endl;
    cout << "AAA: " << sizeof(AAA) << endl;
    cout << "long: " << sizeof(long) << endl;
    cout << "long long: " << sizeof(long long) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    unsigned char c = 0xFF;
    int tt = c;
    cout << tt << endl;
    unsigned char ss[] = "\x31 10f1";
    cout << sizeof(ss) << endl;
    cout << ss << endl;

    A::a = 2;
    B::a = 3;
    cout << A::a << endl;
    A mm;
    mm.fun2();
    B nn;
    nn.fun2();
    return 0;
}
