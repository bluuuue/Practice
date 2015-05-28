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

bool Equals22(std::vector<int> &path)
{
	if(path.empty())
	{
		return false;
	}

	int sum = 0;
	for(std::vector<int>::iterator iter = path.begin();
			iter != path.end(); ++iter)
	{
		sum += *iter;
	}
	
	if(sum == 22)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PrintPath(std::vector<int> &path)
{
}
