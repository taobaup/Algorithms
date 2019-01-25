英文链接: https://leetcode.com/problems/reverse-nodes-in-k-group/  
中文链接: https://leetcode-cn.com/problems/reverse-nodes-in-k-group/

```
分段反转链表，每段k个结点
遍历链表，得到链表的长度num 
num>=k，则开始交换节点 
当k=2时，每段需要交换1次 
当k=3时，每段需要交换2次 
所以i从1开始循环k-1次 
每完成一段后更新pre指针， 
且num减去k直到num<k 
总体来说每个结点会被访问两次 
总时间复杂度为O(2*n)=O(n)，空间复杂度为O(1) 
注意不要遗漏dummy->next = head; 
以及t->next = prev->next;不要写成t->next = cur;
```

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        ListNode *cur = dummy;

        dummy->next = head;

        int num = 0;
        while(cur->next != NULL)
        {
            cur = cur->next;
            ++num;
        }

        while(num >= k)
        {
            cur = prev->next;

            for(int i = 1; i < k; ++i)
            {
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = prev->next;
                prev->next = t;
            }

            prev = cur;
            num -= k;
        }

        return dummy->next;
    }
};
```
