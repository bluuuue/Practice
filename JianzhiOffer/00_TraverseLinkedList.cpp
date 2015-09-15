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

int main()
{
    BinaryTreeNode *pRoot = NULL;
    CreateBinaryTree(pRoot);
    PreTraverseLoops(pRoot);

    PrintTree(pRoot, 3);
    return 0;
}
