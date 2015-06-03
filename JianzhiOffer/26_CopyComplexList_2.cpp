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

ComplexListNode* CloneComplexList(ComplexListNode *pSrcList)
{
	ComplexListNode *pResult = NULL;
	if(pSrcList == NULL)
	{
		return pResult;
	}

	return pResult;
}

int main()
{
	ComplexListNode *pList = NULL;
	CreateComplexList(pList);
	PrintComplexList(pList);

	ComplexListNode *pCopiedList = NULL;
	pCopiedList = CloneComplexList(pList);
	PrintComplexList(pCopiedList);
	return 0;
}

