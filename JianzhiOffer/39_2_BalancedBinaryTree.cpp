#include <iostream>
#include "BinaryTree.h"

int GetTreeDepth(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
    {
        return 0;
    }

    int nLeftDepth = GetTreeDepth(pRoot->m_pLeft);
    int nRightDepth = GetTreeDepth(pRoot->m_pRight);

    return (nLeftDepth > nRightDepth) ? (nLeftDepth + 1) : (nRightDepth + 1);
}

bool IsBalanced1(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
	{
		return true;
	}

	int nLeftDepth = GetTreeDepth(pRoot->m_pLeft);
	int nRightDepth = GetTreeDepth(pRoot->m_pRight);
	int nDiff = nLeftDepth - nRightDepth;
	if (nDiff > 1 || nDiff < -1)
	{
		return false;
	}

	return IsBalanced1(pRoot->m_pLeft) && IsBalanced1(pRoot->m_pRight);
}

bool IsBalanced2(BinaryTreeNode* pRoot, int* pDepth)
{
	if (pRoot == NULL)
	{
		*pDepth = 0;
		return true;
	}

	int nLeftDepth, nRightDepth;
	if (IsBalanced2(pRoot->m_pLeft, &nLeftDepth) && IsBalanced2(pRoot->m_pRight, &nRightDepth))
	{
		int nDiff = nLeftDepth - nRightDepth;
		if (nDiff <= 1 && nDiff >= -1)
		{
			*pDepth = 1 + (nLeftDepth > nRightDepth ? nLeftDepth : nRightDepth);
			return true;
		}
	}

	return false;
}

bool IsBalanced2(BinaryTreeNode* pRoot)
{
	int nDepth = 0;
	return IsBalanced2(pRoot, &nDepth);
}

int main()
{
    BinaryTreeNode *pRoot = NULL;
    CreateBinaryTree(pRoot);
    PrintBinaryTree(pRoot);
    PrintTree(pRoot, GetTreeDepth(pRoot));
    std::cout << "The tree balance is " << IsBalanced1(pRoot) << "." << std::endl;
    std::cout << "The tree balance is " << IsBalanced2(pRoot) << "." << std::endl;

    return 0;
}
