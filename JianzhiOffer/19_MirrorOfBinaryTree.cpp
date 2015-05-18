#include <iostream>

typedef struct BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode*	m_pLeft;
	BinaryTreeNode*	m_pRight;
}*TreePointer;

void CreateBinaryTree(TreePointer &pRoot)
{
	//preorder input
	int nValue ;
	std::cin >> nValue;
	if(nValue == 0)
	{
		pRoot = NULL;
		return ;
	}
	else
	{
		pRoot = new BinaryTreeNode();
		pRoot->m_nValue = nValue;
		CreateBinaryTree(pRoot->m_pLeft);
		CreateBinaryTree(pRoot->m_pRight);
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

void MirrorRecursely(BinaryTreeNode *pNode)
{
	if(pNode == NULL)
	{
		return;
	}
	if(pNode->m_pLeft == NULL && pNode->m_pRight == NULL) 
	{
		return;
	}

	BinaryTreeNode *pTemp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTemp;

	if(pNode->m_pLeft)
	{
		MirrorRecursely(pNode->m_pLeft);
	}
	if(pNode->m_pRight)
	{
		MirrorRecursely(pNode->m_pRight);
	}
}

int main()
{
	BinaryTreeNode *pRoot = NULL;
	CreateBinaryTree(pRoot);
	PrintBinaryTree(pRoot);

	MirrorRecursely(pRoot);
	PrintBinaryTree(pRoot);

	return 0;
}
