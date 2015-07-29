#include <iostream>
using namespace std;

bool FindContinuesSequence(int nSum)
{
	if (nSum < 3)
		return false;

	bool bExist = false;
	int nHead = 1;
	int nTail = 2;
	int nCurSum = nHead + nTail;
	int nMiddle = nSum / 2;

	while (nHead < nTail && nHead <= nMiddle)
	{
		if (nCurSum == nSum)
		{
			bExist = true;
			int nPrint = nHead;
			while (nPrint <= nTail)
			{
				cout << nPrint << "\t";
				++nPrint;
			}
			cout << endl;
			++nTail;
			nCurSum += nTail;
		}
		else if (nCurSum < nSum)
		{
			++nTail;
			nCurSum += nTail;
		}
		else
		{
			nCurSum -= nHead;
			++nHead;
		}
	}

	return bExist;
}

int main()
{
	FindContinuesSequence(9);

	return 0;
}
