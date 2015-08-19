#include <iostream>
using namespace std;

int TwoNumbersSum(int num1, int num2)
{
    int sum, carry;
    do
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;

        num1 = sum;
        num2 = carry;
    }while(num2 != 0);

    return num1;
}

int main()
{
    cout << TwoNumbersSum(4, 4) << endl;
    return 0;
}
