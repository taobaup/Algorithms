// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;

        ListNode *pre = dummy;
        while(pre != NULL)
        {
        	ListNode *cur = pre->next;
        	while(cur && cur->next && cur->val == cur->next->val)
        		cur = cur->next;
        	if(pre->next != cur)
        		pre->next = cur->next;
        	// 注意不要遗漏else
        	// 否则会出错，如 [1,2,3,3,4,4,5] 会得到 [1,2,4,4,5]
        	else
        		pre = pre->next;
        }

        return dummy->next;
    }
};
