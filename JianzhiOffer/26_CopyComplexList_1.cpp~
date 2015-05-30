#include <iostream>

//awkward solution
struct ComplexListNode
{
	int					m_nValue;
	ComplexListNode*	m_pNext;
	ComplexListNode*	m_pSibling;
};

void CreateComplexList(ComplexListNode *CList)
{
	if(CList != NULL)
	{
		return;
	}

	int nInputValue = 0;
	std::cin >> nInputValue;
	if(nInputValue == 0)
	{
		CList = NULL;
		return;
	}

	CList->m_nValue = nInputValue;
	CreateComplexList(CList->m_pNext);

}
