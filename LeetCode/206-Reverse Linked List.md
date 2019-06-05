
英文链接: https://leetcode.com/problems/reverse-linked-list/  
中文链接: https://leetcode-cn.com/problems/reverse-linked-list/

```
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 ```
 
 ```
// 迭代版
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;

        ListNode *newHead = NULL;
        ListNode *prev = NULL, *cur = head;

        while(cur != NULL)
        {
            ListNode *next = cur->next;
            if(next == NULL)
                newHead = cur;

            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return newHead;
    }
};
```


```
// 递归版
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head != NULL && head->next != NULL)
        {
            ListNode *newHead = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;

            return newHead;
        }

        return head;
    }
};
```
