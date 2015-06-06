#include "BinaryTree.h"

void CreateBinaryTree(BiTreePointer &pTreeRoot)
{
	//preorder input
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

void PrintBinaryTree(BinaryTreeNode *pRoot)
{
	//preorder print
	if(pRoot == NULL)
	{
		return ;
	}

	std::cout << pRoot->m_nValue << std::endl;
	PrintBinaryTree(pRoot->m_pLeft);
	PrintBinaryTree(pRoot->m_pRight);
}
