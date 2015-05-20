#include <iostream>
#include <deque>

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

void PrintFromTopToBottom(BinaryTreeNode *pTreeRoot)
{
	if(pTreeRoot == NULL)
	{
		return;
	}

	std::deque<BiTreePointer> dequeTreeNode;
	dequeTreeNode.push_back(pTreeRoot);

	while(dequeTreeNode.size())
	{
		std::cout << dequeTreeNode.front()->m_nValue << "\t";

		if(dequeTreeNode.front()->m_pLeft != NULL)
		{
			dequeTreeNode.push_back(dequeTreeNode.front()->m_pLeft);
		}
		if(dequeTreeNode.front()->m_pRight != NULL)
		{
			dequeTreeNode.push_back(dequeTreeNode.front()->m_pRight);
		}
		dequeTreeNode.pop_front();
	}
}

int main()
{
	BinaryTreeNode *biTree = NULL;
	CreateBinaryTree(biTree);

	return 0;
}

