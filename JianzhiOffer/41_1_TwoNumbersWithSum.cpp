#include <iostream>
using namespace std;

bool FindNumbersWithSum(int data[], int nLength, int nSum, 
		int *num1, int *num2)
{
	if (data == NULL || nLength < 2)
		return false;

	int nTail = nLength - 1;
	int nHead = 0;
	while (nHead < nTail)
	{
		if (data[nHead] + data[nTail] == nSum)
		{
			*num1 = data[nHead];
			*num2 = data[nTail];
			return true;
		}
		if (data[nHead] + data[nTail] < nSum)
			++nHead;
		else
			--nTail;
	}
	return false;
}

int main()
{
	int data[6] = {1, 2, 4, 7, 11, 15};
	int num1, num2;
	bool bFound = FindNumbersWithSum(data, 6, 15, &num1, &num2);
	if (bFound)
		cout << "Has found: " << num1 << "\t" << num2 << "." << endl;
	else
		cout << "Has not found." << endl;

	return 0;
}
