#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int		m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

BinaryTreeNode *ConstructCore(int *startPreOrder, int *endPreOrder,
		int *startInOrder, int *endInOrder)
{
	int rootValue = startPreOrder[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = NULL;
	root->m_pRight = NULL;

	if(startPreOrder == endPreOrder)
	{
		if(startInOrder == endInOrder && *startPreOrder == *startInOrder)
		{
			return root;
		}
		else
		{
			//throw std::exception("Invalid input.");
		}
	}

	//在中序遍历中找到根结点的值
	int *rootInOrder = startInOrder;
	while(rootInOrder <= endInOrder && *rootInOrder != rootValue)
	{
		++rootInOrder;
	}

	if(rootInOrder == endInOrder && *rootInOrder != rootValue)
	{
		//throw std::exception("Invalid input.");
	}

	int leftLength = rootInOrder - startInOrder;
	int *leftPreOrderEnd = startPreOrder + leftLength;
	if(leftLength > 0)
	{
		//构建左子树
		root->m_pLeft = ConstructCore(startPreOrder+1, leftPreOrderEnd, startInOrder, rootInOrder-1);
	}
	if(leftLength < endPreOrder - startPreOrder)
	{
		//构建右子树
		root->m_pRight = ConstructCore(leftPreOrderEnd+1, endPreOrder, rootInOrder+1, endInOrder);
	}

	return root;
}

BinaryTreeNode *Construct(int *preorder, int *inorder, int length)
{
	if(preorder == NULL || inorder == NULL || length < 0)
	{
		return NULL;
	}
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

int printPreOrder(BinaryTreeNode *root)
{
	if(root->m_pLeft != NULL)
	{
		printPreOrder(root->m_pLeft);
	}

	if(root->m_pRight != NULL)
	{
		printPreOrder(root->m_pRight);
	}

	cout << root->m_nValue << endl;
	
	return 0;
}

int main()
{
	//int preOrder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
	//int inOrder[8] = {4, 7, 2, 1, 5, 3, 8, 6};
	//int length = 8;

	int preOrder[7] = {10, 6, 4, 8, 14, 12, 16};
	int inOrder[7] = {4, 6, 8, 10, 12, 14, 16};
	int length = 7;
	BinaryTreeNode *root = Construct(preOrder, inOrder, length);

	printPreOrder(root);

	return 0;
}
