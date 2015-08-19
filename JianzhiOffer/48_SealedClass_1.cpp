#include <iostream>
using namespace std;

class SealedClass1
{
public:
    static SealedClass1* GetInstance()
    {
        return new SealedClass1();
    }
    static void DelInstance(SealedClass1 *pInstance)
    {
        delete pInstance;
    }
private:
    SealedClass1() {}
    ~SealedClass1() {}
};

//class SealedClass2

int main()
{

    return 0;
}
