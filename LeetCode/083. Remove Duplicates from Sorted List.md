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

        ListNode *start = head;
        while(start != NULL)
        {
        	ListNode *cur = start;
        	while(cur->next != NULL && cur->next->val == cur->val)
        		cur = cur->next;

        	start->next = cur->next;
        	start = start->next;
        }

        return head;
    }
};
