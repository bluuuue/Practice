#include <iostream>
using namespace std;

class ClxBase
{
public:
    ClxBase() {};
    virtual ~ClxBase() { cout << "des ClxBase" << endl;};

    virtual void DoSomething() { cout << "Do something in class ClxBase!" << endl; };
};

class ClxDerived : public ClxBase
{
public:
    ClxDerived() {};
    ~ClxDerived() { cout << "Output from the destructor of class ClxDerived!" << endl; }; 

    void DoSomething() { cout << "Do something in class ClxDerived!" << endl; };
};

int main() 
{
    ClxBase *p = new ClxDerived;
    p->DoSomething();
    delete p;
    return 0;
}
