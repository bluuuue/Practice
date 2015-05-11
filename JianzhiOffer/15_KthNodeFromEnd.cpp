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

ListNode* FindKthToTail(ListNode* pListHead, int k)
{
	if(pListHead == NULL || k <= 0)
	{
		return NULL;
	}

	ListNode *pAhead = pListHead;
	ListNode *pBehind = NULL;

	for(int i = 0; i < k - 1; ++i)
	{
		if(pAhead->m_pNext != NULL)
		{
			pAhead = pAhead->m_pNext;
		}
		else
		{
			return NULL;
		}
	}

	pBehind = pListHead;
	while(pAhead->m_pNext != NULL)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	return pBehind;
}

int main()
{
	ListNode **pHead = new ListNode*();
	*pHead = NULL;
	for(int i = 0; i != 10; ++i)
	{
		AddTOTail(pHead, i);
	}

	ListNode *pKthNodeToTail;
	pKthNodeToTail = FindKthToTail(*pHead, 2);

	return 0;
}


