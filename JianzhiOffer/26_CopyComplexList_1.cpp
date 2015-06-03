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
		pIndex = pIndex->m_pNext;

		if(pIndex != NULL)
		{
			pList->m_pNext = new ComplexListNode();
			pList = pList->m_pNext;
		}
		
	}

	return pResult;
}

int FindSiblingNum(ComplexListNode *pList, int nNum)
{
	int nResult = 0;
	if(pList == NULL || nNum <= 0)
	{
		return nResult;
	}

	//Count the length of list
	int nLength = 0;
	ComplexListNode *pCountIndex =  pList;
	while(pCountIndex != NULL)
	{
		++nLength;
		pCountIndex = pCountIndex->m_pNext;
	}

	//Find the position of sibling pointer
	ComplexListNode *pIndex = pList;
	int nIndex = 0;
	while(pIndex != NULL)
	{
		++nIndex;
		if(pIndex->m_nValue == nNum)
		{
			nResult = nIndex;
		}
		pIndex = pIndex->m_pNext;
	}

	return nResult;
}

void CopySecondPointer(ComplexListNode *srcList, ComplexListNodePointer &dstList)
{
	if (srcList == NULL || dstList == NULL)
	{
		return;
	}

	ComplexListNode *pSrcIndex = srcList;
	ComplexListNode *pDstIndex = dstList;

	int nSiblingSeries = 0;

	while (pSrcIndex != NULL && pDstIndex != NULL)
	{
		if(pSrcIndex->m_pSibling != NULL)
		{
			nSiblingSeries = FindSiblingNum(srcList, pSrcIndex->m_pSibling->m_nValue);
		}
		else
		{
			nSiblingSeries = 0;
		}

		if(nSiblingSeries != 0)
		{
			ComplexListNode *pTempIndex = dstList;
			while(--nSiblingSeries)
			{
				pTempIndex = pTempIndex->m_pNext;
			}
			pDstIndex->m_pSibling = pTempIndex;
		}
		else
		{
			pDstIndex->m_pSibling = NULL;
		}

		pSrcIndex = pSrcIndex->m_pNext;
		pDstIndex = pDstIndex->m_pNext;
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
	PrintComplexList(pList);

	ComplexListNode *pCopiedList = NULL;
	pCopiedList = CloneComplexList(pList);
	PrintComplexList(pCopiedList);
	return 0;
}

