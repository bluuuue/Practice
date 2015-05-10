#include <iostream>
using namespace std;

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
		printf("%d\n", pHead->m_nValue);
	}
}

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
	if(!pListHead || !pToBeDeleted)
	{
		return;
	}

	//The node to be deleted is not the tail node.
	if(pToBeDeleted->m_pNext != NULL)
	{
		pToBeDeleted->m_nValue = pToBeDeleted->m_pNext->m_nValue;
		pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;
	}
	//The list has only one node.
	else if(*pListHead == pToBeDeleted)
	{
		*pListHead = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
	//The list has more than one node, the node to be deleted is the tail node.
	else
	{
		ListNode *pIndex = *pListHead;
		while(pIndex->m_pNext != pToBeDeleted)
		{
			pIndex = pIndex->m_pNext;
		}
		pIndex->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

int main()
{
	cout << endl;
	ListNode **pHead;
	*pHead = NULL;
	for(int i = 0; i != 10; ++i)
	{
		AddTOTail(pHead, i);
	}
	//std::cout << "The old linked list: " << std::endl;
	PrintListReversingly_Recursively(*pHead);
	printf("\n");
/*	
	ListNode *pToBeDeleted = *pHead;
	int nNodeToBeDeletedNum = 5;
	while(--nNodeToBeDeletedNum)
	{
		pToBeDeleted = pToBeDeleted->m_pNext;
	}
	DeleteNode(pHead, pToBeDeleted);
	//std::cout << "The new linked list: " << std::endl;
	PrintListReversingly_Recursively(*pHead);
	//std::cout << std::endl;
	*/
	

	return 0;
}
