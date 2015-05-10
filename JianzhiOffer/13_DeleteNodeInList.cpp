#include <iostream>

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

ListNode *AddElement(int value, ListNode *list)
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

void PrintListReversingly_Recursively(ListNode* pHead)
{
	if(pHead != NULL)
	{
		if(pHead->m_pNext != NULL)
		{
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nValue);
	}
}

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{

}

int main()
{
	ListNode *list = NULL;
	for (int i = 1; i <= 10; ++i)
	{
		list = AddElement(i, list);
	}

	PrintListReversingly_Recursively(list);

	return 0;
}