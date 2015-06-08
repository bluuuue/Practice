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

    pCurrent->m_pLeft = 


BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode *pLastNodeInList = NULL;
    ConvertNode(pRootOfTree, &pLastNodeInList);

}

int main()
{
	BinaryTreeNode *pRoot = NULL;

	CreateBinaryTree(pRoot);
	PrintBinaryTree(pRoot);

	return 0;
}
