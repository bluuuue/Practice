#include <iostream>

typedef struct BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode*	m_pLeft;
	BinaryTreeNode*	m_pRight;
}*TreePointer;

void CreateBinaryTree(BinaryTreeNode **pRoot)
{
	//preorder input
	if(*pRoot == NULL)
	{
		*pRoot = new BinaryTreeNode();
	}

	int nValue ;
	std::cin >> nValue;
	if(nValue == 0)
	{
		*pRoot = NULL;
		return ;
	}
	else
	{
		(*pRoot)->m_nValue = nValue;
		CreateBinaryTree(&((*pRoot)->m_pLeft));
		CreateBinaryTree(&((*pRoot)->m_pRight));
	}
}

void CreateBinaryTree_2(TreePointer &pRoot)
{
	//preorder input
	if(pRoot == NULL)
	{
		pRoot = new BinaryTreeNode();
	}

	int nValue ;
	std::cin >> nValue;
	if(nValue == 0)
	{
		pRoot = NULL;
		return ;
	}
	else
	{
		pRoot->m_nValue = nValue;
		CreateBinaryTree_2(pRoot->m_pLeft);
		CreateBinaryTree_2(pRoot->m_pRight);
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

bool DoesTree1HasTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
	if(pRoot2 == NULL)
	{
		return true;
	}
	else if(pRoot1 == NULL)
	{
		return false;
	}

	if(pRoot1->m_nValue != pRoot2->m_nValue)
	{
		return false;
	}

	return DoesTree1HasTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HasTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool HasSubtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
	if(pRoot2 == NULL)
	{
		return true;
	}
	else if(pRoot1 == NULL)
	{
		return false;
	}

	bool result = false;

	if(pRoot1->m_nValue == pRoot2->m_nValue)
	{
		result = DoesTree1HasTree2(pRoot1, pRoot2);
	}
	if(!result)
	{
		result = HasSubtree(pRoot1->m_pLeft, pRoot2);
	}
	if(!result)
	{
		result = HasSubtree(pRoot1->m_pRight, pRoot2);
	}

	return result;
}
	
int main()
{
	BinaryTreeNode **pRoot1 = new BinaryTreeNode*(); 
	CreateBinaryTree(pRoot1);
	PrintBinaryTree(*pRoot1);

	BinaryTreeNode *pRoot2 = NULL;
	CreateBinaryTree_2(pRoot2);
	PrintBinaryTree(pRoot2);

	bool bTree1HasTree2 = HasSubtree(*pRoot1, pRoot2);
	std::cout << bTree1HasTree2 << std::endl;

	return 0;
}
