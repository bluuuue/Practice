#include <iostream>

struct ListNode
{
	int			m_nValue;
	ListNode*	m_pNext;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if(pListHead == NULL || k == 0)
	{
		return NULL;
	}
	
