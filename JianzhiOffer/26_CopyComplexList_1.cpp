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

void CreateComplexList(ComplexListNodePointer &CList)
{
	if(CList != NULL)
	{
		return;
	}

	CreateList(CList);
}



int main()
{
	ComplexListNode *pList = NULL;
	CreateComplexList(pList);

	return 0;
}

