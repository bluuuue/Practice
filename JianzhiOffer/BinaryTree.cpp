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

bool PrintTree(BinaryTreeNode *pRoot, int nLayer)
{
    if(pRoot==NULL)
    {
        return false;
    }

    PrintTree(pRoot->m_pRight,nLayer+3);
    for(int i = 0; i < nLayer; i++)
    {
		std::cout << " ";
    }
	std::cout << pRoot->m_nValue << std::endl;
    PrintTree(pRoot->m_pLeft, nLayer + 3);

    return true;
}
