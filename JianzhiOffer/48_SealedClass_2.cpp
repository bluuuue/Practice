#include <iostream>
using namespace std;

template <typename T> class MakeSealed
{
    friend T;
private: 
    MakeSealed() {}
    ~MakeSealed() {}
};

class SealedClass2: virtual public MakeSealed<SealedClass2>
{
public:
    SealedClass2() {}
    ~SealedClass2() {}
};

//class Try: public SealedClass2
//{
//public:
//    Try() {}
//    ~Try() {}
//};

int main()
{
    SealedClass2 test;

    return 0;
}
