#include <iostream>
#include <stack>
using namespace std;
#include "BinaryTree.h"

void PreTraverseLoops(BiTreePointer &pRoot)
{
    stack<BinaryTreeNode *> NodeStack;
    BinaryTreeNode *pIndex = pRoot;

    while (pIndex != NULL || !NodeStack.empty())
    {
        while (pIndex != NULL)
        {
            cout << pIndex->m_nValue << "\t";
            NodeStack.push(pIndex);
            pIndex = pIndex->m_pLeft;
        }
        if (!NodeStack.empty())
        {
            pIndex = NodeStack.top();
            NodeStack.pop();
            pIndex = pIndex->m_pRight;
        }
    }
    cout << endl;
}

void InorderTraverseLoops(BinaryTreeNode *pRoot)
{
	stack<BinaryTreeNode *> NodeStack;
	BinaryTreeNode *pIndex = pRoot;

	while (pIndex != NULL || !NodeStack.empty())
	{
		while (pIndex != NULL)
		{
			NodeStack.push(pIndex);
			pIndex = pIndex->m_pLeft;
		}
		if (!NodeStack.empty())
		{
			pIndex = NodeStack.top();
			NodeStack.pop();
			cout << pIndex->m_nValue << "\t";
			pIndex = pIndex->m_pRight;
		}
	}
	cout << endl;
}

void PostorderTraverseLoops(BinaryTreeNode *pRoot)
{
	stack<pair<BinaryTreeNode*, bool> > s;
	bool bVisited = false;
	s.push(make_pair(pRoot, false));
	BinaryTreeNode *pIndex;
	while (!s.empty())
	{
		pIndex = s.top().first;
		bVisited = s.top().second;
		s.pop();
		if (pIndex == NULL)
			continue;
		if (bVisited)
			cout << pIndex->m_nValue << "\t";
		else
		{
			s.push(make_pair(pIndex, true));
			s.push(make_pair(pIndex->m_pRight, false));
			s.push(make_pair(pIndex->m_pLeft, false));
		}
	}
	cout << endl;
}

int main()
{
    BinaryTreeNode *pRoot = NULL;
    CreateBinaryTree(pRoot);
    PreTraverseLoops(pRoot);
	InorderTraverseLoops(pRoot);
	PostorderTraverseLoops(pRoot);

    PrintTree(pRoot, 3);
    return 0;
}
