/********
**Longest Increase Substring**
**Not finish.....
********/
#include <iostream>
using namespace std;

int LIS(int *num, int nLength, int pos)
{
	//Time complexity: O(n2)
	if (num == NULL || nLength <= 0 || pos > nLength)
		return 0;

	if (pos == 1)
		return 1;
	
}

int LIS_fast(int *num, int nLength, int pos)
{
	//Time complexity: O(n2)
	if (num == NULL || nLength <= 0 || pos > nLength)
		return 0;

	if (pos == 1)
		return 1;
	
}

int main()
{
	int num[6] = {5, 3, 4, 8, 6, 7};

	for (int i = 1; i <= 6; ++i)
		cout << "Num " << i << ": " << LIS(num, 6, i) << endl;
    return 0;
}
