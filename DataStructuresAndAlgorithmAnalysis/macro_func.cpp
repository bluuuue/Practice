#include <iostream>
using namespace std;

#define LENGTH(A) (sizeof(A) / sizeof(A[0]))

int main()
{
    int arrInt[239];
    char arrChar[23];
    cout << "int length: " << LENGTH(arrInt) << endl;
    cout << "char length: " << LENGTH(arrChar) << endl;

    return 0;
}
