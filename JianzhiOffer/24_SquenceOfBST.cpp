#include <iostream>

typedef struct BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode*	m_pLeft;
	BinaryTreeNode*	m_pRight;
}*BiTreePointer;

void CreateBinaryTree(BiTreePointer &pTreeRoot)
{
	if(pTreeRoot != NULL)
	{
		return ;
	}

	int nData = -1;
	std::cin >> nData;
	pTreeRoot = new BinaryTreeNode();
	if(nData == 0)
	{
		pTreeRoot = NULL;
		return;
	}
	else
	{
		pTreeRoot->m_nValue = nData;
		CreateBinaryTree(pTreeRoot->m_pLeft);
		CreateBinaryTree(pTreeRoot->m_pRight);
	}
}

bool VerifySquenceOfBST(int sequence[], int nLength)
{
	if(sequence == NULL || nLength <= 0)
	{
		return false;
	}

	int nRootValue = sequence[nLength - 1];

	int nLeftEndSeries = -1;

	for(int nSeries = 0; nSeries < nLength; ++nSeries)
	{
		if(sequence[nSeries] < nRootValue)
		{
			nLeftEndSeries = nSeries ;
		}
		if(sequence[nSeries] > nRootValue)
		{
			nLeftEndSeries = nSeries - 1;
			break;
		}
	}

	if(nLeftEndSeries == -1)
	{
		for(int i = 0; i < nLength - 1; ++i)
		{
			if(sequence[i] < nRootValue)
			{
				return false;
			}
		}
	}
	else
	{
		for(int i = 0; i <= nLeftEndSeries; ++i)
		{
			if(sequence[i] > nRootValue)
			{
				return false;
			}
		}
		for(int i = nLeftEndSeries + 1; i < nLength - 1; ++i)
		{
			if(sequence[i] < nRootValue)
			{
				return false;
			}
		}
	}

	bool bLeftSubTree = true;
	if(nLeftEndSeries - 1 >= 2)
	{
		bLeftSubTree = VerifySquenceOfBST(sequence, nLeftEndSeries + 1);
	}

	bool bRightSubTree = true;
	if(nLength - nLeftEndSeries - 2 >= 2)
	{
		bRightSubTree = VerifySquenceOfBST(sequence + nLeftEndSeries + 1, nLength - 2 - nLeftEndSeries);
	}

	return (bLeftSubTree && bRightSubTree);
}

int main()
{
	int sequence1[7] = {5, 7, 6, 9, 11, 10, 8};
	std::cout << VerifySquenceOfBST(sequence1, 7) << std::endl;

	int sequence2[4] = {7, 4, 6, 5};
	std::cout << VerifySquenceOfBST(sequence2, 4) << std::endl;

	int sequence3[1] = {5};
	std::cout << VerifySquenceOfBST(sequence3, 1) << std::endl;

	int *sequence4 = NULL;
	std::cout << VerifySquenceOfBST(sequence4, 0) << std::endl;

	return 0;
}

