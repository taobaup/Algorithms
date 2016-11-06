//Reverse Linked List
//遍历链表，依次往前反转即可，分为迭代版和递归版两种
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//迭代版
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
            
        ListNode *newHead=NULL;
        ListNode *prev=NULL,*cur=head;
        
        while(cur)
        {
            ListNode *next=cur->next;
            if(next==NULL)
                newHead=cur;
            
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        
        return newHead;
    }
};
//递归版
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head&&head->next)
        {
            ListNode *newHead=reverseList(head->next);
            head->next->next=head;
            head->next=NULL;
            return newHead;
        }
        return head;
    }
};
