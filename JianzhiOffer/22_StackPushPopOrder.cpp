#include <iostream>
#include <stack>

bool IsPopOrder(const int *pPush, const int *pPop, int nLength)
{
	bool bIsPopOrder = false;

	if(pPush == NULL || pPop == NULL || nLength <= 0)
	{
		return bIsPopOrder;
	}

	std::stack<int> stackData;

	int nIndex = 0;
	int nPushPosition = 0;
	int nPushPosition2 = 0;

	while(nIndex < nLength)
	{
		for(int nPushIndex = 0; nPushIndex < nLength; ++nPushIndex)
		{
			if(pPush[nPushIndex] == pPop[nIndex])
			{
				nPushPosition = nPushIndex;
				break;
			}
			else
			{
				nPushPosition = -1;
			}
		}

		if(nPushPosition == -1)
		{
			break;
		}
		else
		{
			int nStackSize = stackData.size();
			if(nStackSize > 0)
			{
				if(stackData.top() == pPop[nIndex])
				{
					stackData.pop();
				}
				else
				{
					for(int nTempPush = nPushPosition2; nTempPush <= nPushPosition; ++nTempPush)
					{
						stackData.push(pPush[nTempPush]);
					}
					if(stackData.size() == nStackSize)
					{
						break;
					}
					else
					{
						stackData.pop();
					}
				}
			}
			else
			{
				for(int nTempPush = nPushPosition2; nTempPush <= nPushPosition; ++nTempPush)
				{
					stackData.push(pPush[nTempPush]);
				}
				stackData.pop();
				nPushPosition2 = nPushPosition + 1;
			}
		}
		++nIndex;

		if(nIndex >= nLength)
		{
			bIsPopOrder = true;
		}
	}

	return bIsPopOrder;
}

int main()
{
	int pushOrder[5] = {1, 2, 3, 4, 5};
	int popOrder[5] = {4, 5, 3, 2, 1};

	std::cout << IsPopOrder(pushOrder, popOrder, 5) << std::endl;

	return 0;
}
