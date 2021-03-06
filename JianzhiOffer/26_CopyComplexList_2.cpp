#include <iostream>

typedef struct ComplexListNode
{
	int					m_nValue;
	ComplexListNode*	m_pNext;
	ComplexListNode*	m_pSibling;
}*ComplexListNodePointer;

void CreateList(ComplexListNodePointer &CList)
{
	ComplexListNode *pListTemp = new ComplexListNode();

	int nInputValue = 0;
	std::cin >> nInputValue;
	if(nInputValue == 0)
	{
		pListTemp = NULL;
		return;
	}

	pListTemp->m_nValue = nInputValue;
	CreateList(pListTemp->m_pNext);
	CList = pListTemp;
}

void AddSecondPointer(ComplexListNodePointer &CList, int nLength)
{
	if (nLength < 5)
	{
		return;
	}

	int nSeries = 1;
	ComplexListNodePointer pIndex = CList;
	while (nSeries <= nLength - 2)
	{
		pIndex->m_pSibling = pIndex->m_pNext->m_pNext;
		pIndex = pIndex->m_pNext;
		++nSeries;
	}

	pIndex->m_pSibling = NULL;
	pIndex->m_pNext->m_pSibling = CList;
}

void CreateComplexList(ComplexListNodePointer &CList)
{
	if(CList != NULL)
	{
		return;
	}

	std::cout << "Please input 5 numbers: " << std::endl;
	CreateList(CList);
	AddSecondPointer(CList, 5);
}

void PrintComplexList(ComplexListNode *list)
{
	if(list == NULL)
	{
		return;
	}
	
	std::cout << "The first series: " << std::endl;
	ComplexListNode *pIndex1 = list;
	while(pIndex1 != NULL)
	{
		std::cout << pIndex1->m_nValue << "\t";
		pIndex1 = pIndex1->m_pNext;
	}
	std::cout << std::endl;

	std::cout << "The second series: " << std::endl;
	ComplexListNode *pIndex2 = list;
	while(pIndex2 != NULL)
	{
		if(pIndex2->m_pSibling != NULL)
		{
			std::cout << pIndex2->m_pSibling->m_nValue << "\t";
		}
		else
		{
			std::cout << "0\t";
		}
		pIndex2 = pIndex2->m_pNext;
	}
	std::cout << std::endl;
}

void CloneNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	while(pNode != NULL)
	{
		ComplexListNode *pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = NULL;

		pNode->m_pNext = pCloned;

		pNode = pCloned->m_pNext;
	}
}

void ConnectSiblingNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	while(pNode != NULL)
	{
		ComplexListNode *pCloned = pNode->m_pNext;
		if(pNode->m_pSibling != NULL)
		{
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pCloned->m_pNext;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	ComplexListNode *pClonedHead = NULL;
	ComplexListNode *pClonedNode = NULL;

	if(pNode != NULL)
	{
		pClonedHead = pNode->m_pNext;
		pClonedNode = pClonedHead;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	while(pNode != NULL)
	{
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	return pClonedHead;
}

ComplexListNode* CloneComplexList(ComplexListNode *pSrcList)
{
	ComplexListNode *pResult = NULL;
	if(pSrcList == NULL)
	{
		return pResult;
	}

	CloneNodes(pSrcList);
	ConnectSiblingNodes(pSrcList);
	pResult = ReconnectNodes(pSrcList);

	return pResult;
}

int main()
{
	ComplexListNode *pList = NULL;
	CreateComplexList(pList);
	PrintComplexList(pList);

	ComplexListNode *pCopiedList = NULL;
	pCopiedList = CloneComplexList(pList);
	PrintComplexList(pList);
	PrintComplexList(pCopiedList);
	return 0;
}

