#include <iostream>

struct BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode*	m_pLeft;
	BinaryTreeNode*	m_pRight;
};

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

bool DoesTree1HasTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pTree2)
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
	
int main()
{

	return 0;
}
