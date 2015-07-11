#include<iostream>
#include "BinaryTree.h"

int GetTreeDepth(BinaryTreeNode* pRoot)
{
    if (pRoot == NULL)
    {
        return 0;
    }

    int nLeftDepth = GetTreeDepth(pRoot->m_pLeft);
    int nRightDepth = GetTreeDepth(pRoot->m_pRight);

    return (nLeftDepth > nRightDepth) ? (nLeftDepth + 1) : (nRightDepth + 1);
}

int main()
{
    BinaryTreeNode *pRoot = NULL;
    CreateBinaryTree(pRoot);
    PrintBinaryTree(pRoot);
    PrintTree(pRoot, GetTreeDepth(pRoot));
    std::cout << "The depth of the tree is " << GetTreeDepth(pRoot) << "." << std::endl;

    return 0;
}
    
