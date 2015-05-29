#include <iostream>
#include <vector>

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
	if(path.empty())
	{
		return;
	}

	for(std::vector<int>::iterator iter = path.begin();
		iter != path.end(); ++iter)
	{
		std::cout << *iter << "\t";
	}
	std::cout << std::endl;
}

void TraverseTree(BinaryTreeNode *root, std::vector<int> &vecRoute)
{
	if(root == NULL && vecRoute.empty())
	{
		return;
	}
	else if(root == NULL)
	{
		return;
	}
	else
	{
		vecRoute.push_back(root->m_nValue);
//		if(Equals22(vecRoute))
//		{
//			PrintPath(vecRoute);
//		}
		PrintPath(vecRoute);
	}

	if(root->m_pLeft != NULL)
	{
		TraverseTree(root->m_pLeft, vecRoute);
	}
	else if(root->m_pRight != NULL)
	{
		TraverseTree(root->m_pRight, vecRoute);
	}
	vecRoute.pop_back();
}

void PrintRightPath(BiTreePointer pRoot)
{
	if(pRoot == NULL)
	{
		return;
	}

	std::vector<int> vecRoute;
	TraverseTree(pRoot, vecRoute);

}

int main()
{
	BinaryTreeNode *pRoot = NULL;
	CreateBinaryTree(pRoot);

	PrintRightPath(pRoot);

	return 0;
}
