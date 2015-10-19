/**
   * Definition for singly-linked list.
    * struct ListNode {
     *     int val;
      *     ListNode *next;
       *     ListNode(int x) : val(x), next(NULL) {}
        * };
         */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int nLength = 0;
        ListNode *pNode = head;
        while (pNode != NULL) {
            pNode = pNode->next;
            ++nLength;
        }
        int nCount = nLength - n;
        pNode = head;
        pPre = pNode;
        while (nCount--) {
            pPre = pNode;
            pNode = pNode->next;
        }
        pPre->next = pNode->next;
        return head;
    }
};
