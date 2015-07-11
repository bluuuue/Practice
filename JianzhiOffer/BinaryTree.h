#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

typedef struct BinaryTreeNode
{
	int 				m_nValue;
	BinaryTreeNode*		m_pLeft;
	BinaryTreeNode*		m_pRight;
}*BiTreePointer;

void CreateBinaryTree(BiTreePointer &pTreeRoot);

void PrintBinaryTree(BinaryTreeNode *pRoot);

bool PrintTree(BinaryTreeNode *pRoot, int nLayer);

#endif
