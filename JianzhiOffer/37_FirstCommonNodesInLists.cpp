#include <iostream>

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

ListNode *AddElement(ListNode *list, int value)
{
	ListNode *pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if (list == NULL)
	{
		list = pNew;
	}
	else
	{
		ListNode *pEnd = list;
		while(pEnd->m_pNext != NULL)
		{
			pEnd = pEnd->m_pNext;
		}
		pEnd->m_pNext = pNew;
	}

	return list;
}

void PrintList(ListNode *pHead)
{
    ListNode *pNode = pHead;
    while (pNode != NULL)
    {
        std::cout << pNode->m_nValue << "\t";
        pNode = pNode->m_pNext;
    }
    std::cout << std::endl;
}

int GetListLength(ListNode *pHead)
{
    int nLength = 0;

    ListNode* pIndex = pHead;
    while (pIndex != NULL)
    {
        ++nLength;
        pIndex = pIndex->m_pNext;
    }

    return nLength;
}

ListNode* GetCommonNodes(ListNode* ListA, ListNode* ListB)
{
    if (ListA == NULL || ListB == NULL)
    {
        return NULL;
    }

    int nLengthA = GetListLength(ListA);
    int nLengthB = GetListLength(ListB);
    int nLengthDif = nLengthA - nLengthB;

    ListNode *pLongList = ListA;
    ListNode *pShortList = ListB;
    if (nLengthDif < 0)
    {
        pLongList = ListB;
        pShortList = ListA;
        nLengthDif = 0 - nLengthDif;
    }

    for (int i = 0; i != nLengthDif; ++i)
    {
        pLongList = pLongList->m_pNext;
    }

    ListNode *pCommonNode = NULL;
    while (pLongList != NULL && pShortList != NULL)
    {
        if (pLongList == pShortList)
        {
            pCommonNode = pLongList;
            return pCommonNode;
        }

        pLongList = pLongList->m_pNext;
        pShortList = pShortList->m_pNext;
    }

    return pCommonNode;
}

int main()
{
    //Create 2 lists: listA and listB.
    ListNode *pHeadA = NULL;
    for (int i = 0; i != 10; ++i)
    {
        pHeadA = AddElement(pHeadA, i + 1);
    }
    PrintList(pHeadA);

    ListNode *pHeadB = NULL;
    for (int j = 0; j != 3; ++j)
    {
        pHeadB = AddElement(pHeadB, (j + 1) * 2);
    }
    ListNode *pHeadAIndexA = pHeadA;
    ListNode *pHeadBIndexB = pHeadB;
    int nCountA = 4;
    int nCountB = 3;
    while (nCountA--)
    {
        pHeadAIndexA = pHeadAIndexA->m_pNext;
    }
    while (pHeadBIndexB->m_pNext != NULL)
    {
        pHeadBIndexB = pHeadBIndexB->m_pNext;
    }
    pHeadBIndexB->m_pNext = pHeadAIndexA;
    PrintList(pHeadB);


    return 0;
}
