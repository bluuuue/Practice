#include <iostream>
#include "BinaryTree.h"

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
    if(pNode == NULL)
    {
        return;
    }

    BinaryTreeNode *pCurrent = pNode;

    if(pCurrent->m_pLeft != NULL)
    {
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
    }

	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != NULL)
	{
		(*pLastNodeInList)->m_pRight = pCurrent;
	}

	*pLastNodeInList = pCurrent;

	if (pCurrent->m_pRight != NULL)
	{
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);
	}
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode *pLastNodeInList = NULL;
    ConvertNode(pRootOfTree, &pLastNodeInList);

	BinaryTreeNode *pHeadOfList = pLastNodeInList;
	while (pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL)
	{
		pHeadOfList = pHeadOfList->m_pLeft;
	}
	return pHeadOfList;

}

int main()
{
	BinaryTreeNode *pRoot = NULL;

	CreateBinaryTree(pRoot);
	PrintBinaryTree(pRoot);

	BinaryTreeNode *pResult = NULL;
	pResult = Convert(pRoot);

	return 0;
}

