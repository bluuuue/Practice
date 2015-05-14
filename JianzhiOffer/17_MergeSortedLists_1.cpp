#include <iostream>

struct ListNode
{
	int			m_nValue;
	ListNode*	m_pNext;
};

void AddTOTail(ListNode **pHead, int value)
{
	ListNode *pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if(*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode *pNode = *pHead;

		while(pNode->m_pNext != NULL)
		{
			pNode = pNode->m_pNext;
		}

		pNode->m_pNext = pNew;
	}
}

void PrintLinkedList(ListNode *list)
{
	if (list == NULL)
	{
		return;
	}

	ListNode *index = list;
	while (index != NULL)
	{
		std::cout << index->m_nValue << "\t";
		index = index->m_pNext;
	}
	std::cout << std::endl;
}

ListNode *MergeLists(ListNode *pHeadA, ListNode *pHeadB)
{
	if(pHeadA == NULL)
	{
		return pHeadB;
	}
	else if(pHeadB == NULL)
	{
		return pHeadA;
	}

	ListNode *pMergedList = NULL;
	ListNode *pIndex = NULL;
	while(pHeadA != NULL || pHeadB != NULL)
	{
		if(pHeadA == NULL)
		{
			pIndex->m_pNext = pHeadB;
			break;
		}
		else if(pHeadB == NULL)
		{
			pIndex->m_pNext = pHeadA;
			break;
		}

		if(pHeadA->m_nValue < pHeadB->m_nValue)
		{
			if(pIndex == NULL)
			{
				pIndex = pHeadA;
				pMergedList = pHeadA;
			}
			else
			{
				pIndex->m_pNext = pHeadA;
				pIndex = pIndex->m_pNext;
			}
			pHeadA = pHeadA->m_pNext;
		}
		else
		{
			if(pIndex == NULL)
			{
				pIndex = pHeadB;
				pMergedList = pHeadB;
			}
			else
			{
				pIndex->m_pNext = pHeadB;
				pIndex = pIndex->m_pNext;
			}
			pHeadB = pHeadB->m_pNext;
		}
	}

	return pMergedList;
}

int main()
{
	ListNode **pHeadA = new ListNode*();
	*pHeadA = NULL;
	for(int i = 0; i != 3; ++i)
	{
		AddTOTail(pHeadA, i * 2 + 1);
	}
	PrintLinkedList(*pHeadA);

	ListNode **pHeadB = new ListNode*();
	*pHeadB = NULL;
	for(int i = 0; i != 8; ++i)
	{
		AddTOTail(pHeadB, i * 2);
	}
	PrintLinkedList(*pHeadB);

	ListNode *pMergedList = NULL;
	pMergedList = MergeLists(*pHeadA, *pHeadB);
	PrintLinkedList(pMergedList);

	return 0;
}

