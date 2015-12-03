#include <iostream>
using namespace std;

#define LENGTH(A) (sizeof(A) / sizeof(A[0]))
#define SWAP1(A, B) (A = A^B, B = A^B, A = A^B)
#define SWAP2(A, B) {A += B; B = A - B; A = A - B;}

int main()
{
    int arrInt[239];
    char arrChar[23];
    cout << "int length: " << LENGTH(arrInt) << endl;
    cout << "char length: " << LENGTH(arrChar) << endl;

    int A = 18;
    int B = -234;
    SWAP1(A, B);
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    SWAP2(A, B);
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;


    return 0;
}
