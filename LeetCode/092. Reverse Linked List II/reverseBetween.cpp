Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(head == NULL)
    		return NULL;

    	ListNode dummy(-1);
    	dummy.next = head;

    	ListNode *cur = &dummy;
    	for(int i = 1; i < m; ++i)
    		cur = cur->next;

    	ListNode *pre = cur;
    	ListNode *last = cur->next;
    	ListNode *front = NULL;

    	for(int i = m; i <= n; ++i)
    	{
    		cur = pre->next;
    		pre->next = cur->next;
    		cur->next = front;
    		front = cur;
    	}

    	cur = pre->next;
    	pre->next = front;
    	last->next = cur;

    	return dummy.next;
    }
};
