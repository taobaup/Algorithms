//Merge Two Sorted Lists 
//遍历两个链表，依次比较即可，解法分迭代版和递归版两种
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//迭代版
//时间复杂度为O(min(m,n))，空间复杂度为O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;

        ListNode dummy(-1);
        ListNode *p=&dummy;

        while(l1&&l2)
        {
            if(l1->val<=l2->val)
            {
                p->next=l1;
                l1=l1->next;
            }
            else
            {
                p->next=l2;
                l2=l2->next;
            }
            p=p->next;
        }

        p->next=l1?l1:l2;

        return dummy.next;
    }
};
//递归版
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        ListNode *p=NULL;
        if(l1->val<l2->val)
        {
            p=l1;
            p->next=mergeTwoLists(l1->next,l2);
        }
        else
        {
            p=l2;
            p->next=mergeTwoLists(l1,l2->next);
        }
        
        return p;
    }
};
