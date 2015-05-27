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

