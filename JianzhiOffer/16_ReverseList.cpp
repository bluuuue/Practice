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
ListNode* ReverseList(ListNode *pNode)
{
	if(pNode == NULL)
	{
		return NULL;
	}

	ListNode *pBehind = NULL;
	ListNode *pIndex = pNode;
	ListNode *pReversedHead= NULL;

	while(pIndex != NULL)
	{
		ListNode *pAhead = pIndex->m_pNext;
		if (pAhead == NULL)
		{
			pReversedHead = pIndex;
		}
		pIndex->m_pNext = pBehind;
		pBehind = pIndex;
		pIndex = pAhead;
	}

	return pReversedHead;
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

int main()
{
	ListNode **pHead = new ListNode*();
	*pHead = NULL;
	for(int i = 0; i != 10; ++i)
	{
		AddTOTail(pHead, i);
	}
	PrintLinkedList(*pHead);

	ListNode *pReverse = NULL;
	pReverse = ReverseList(*pHead);
	PrintLinkedList(pReverse);

	return 0;
}

