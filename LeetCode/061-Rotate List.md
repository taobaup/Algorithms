
英文链接: https://leetcode.com/problems/rotate-list/  
中文链接: https://leetcode-cn.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;

        ListNode *cur = head;
        int n = 1;
        while(cur->next != NULL)
        {
            ++n;
            cur = cur->next;
        }

        cur->next = head;
        int m = n - k % n;
        for(int i = 0; i < m; ++i)
        {
            cur = cur->next;
        }

        ListNode *newHead = cur->next;
        cur->next = NULL;

        return newHead;
    }
};
```
