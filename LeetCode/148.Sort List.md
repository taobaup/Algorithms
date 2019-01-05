英文链接: https://leetcode.com/problems/sort-list/  
中文链接: https://leetcode-cn.com/problems/sort-list/

```
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```

```
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        // 不要写成  ListNode *prev = NULL;
        ListNode *prev = head;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        // 写成  return mergeTwoListsIterative(head, slow);   是错误的
        return mergeTwoListsIterative(sortList(head), sortList(slow));
        // return mergeTwoListsRecursive(sortList(head), sortList(slow));
    }

    ListNode* mergeTwoListsIterative(ListNode* l1, ListNode *l2)
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;

        ListNode dummy(INT_MIN);
        ListNode *cur = &dummy;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        cur->next = l1 != NULL ? l1 : l2;

        return dummy.next;
    } 

    ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode *l2)
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;

        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoListsRecursive(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoListsRecursive(l2->next, l1);
            return l2;
        }
    }

};
```
