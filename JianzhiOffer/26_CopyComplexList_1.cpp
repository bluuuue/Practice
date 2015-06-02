#include <iostream>

//awkward solution
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

ComplexListNode* CopyList(ComplexListNode *CList)
{
	ComplexListNode *pList = NULL;

	if (CList == NULL)
	{
		return pList;
	}

	ComplexListNode *pIndex = CList;
	pList = new ComplexListNode();
	ComplexListNode *pResult = pList;
	while(pIndex != NULL)
	{
		pList->m_nValue = pIndex->m_nValue;
		pList->m_pNext = new ComplexListNode();
		pList = pList->m_pNext;
		pIndex = pIndex->m_pNext;
	}

	return pResult;
}

void CopySecondPointer(ComplexListNode *srcList, ComplexListNodePointer &dstList)
{
	if (srcList == NULL || dstList == NULL)
	{
		return;
	}

	ComplexListNode *pSrcIndex = srcList;
	ComplexListNode *pDstIndex = dstList;

	while (pSrcIndex != NULL)
	{

	}
}

ComplexListNode* CloneComplexList(ComplexListNode *CList)
{
	ComplexListNode *pList = NULL;

	if (CList == NULL)
	{
		return pList;
	}

	pList = CopyList(CList);
	CopySecondPointer(CList, pList);

	return pList;
}

int main()
{
	ComplexListNode *pList = NULL;
	CreateComplexList(pList);

	ComplexListNode *pCopiedList = NULL;
	pCopiedList = CloneComplexList(pList);
	return 0;
}

