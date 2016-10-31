//Remove Nth Node From End of List
//利用快慢指针，快指针先往前走n+1步
//快指针指向倒数第1个结点
//慢指针指向倒数第n+1个结点
//由于被删除的结点可能为首结点
//故链表中应设立一个头结点
//时间复杂度为O(n)，空间复杂度为O(1)
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
        if(head==NULL||n==0)
            return NULL;
            
        ListNode dummy{-1};
        dummy.next=head;
        ListNode *fast=&dummy,*slow=&dummy;
        
        for(int i=0;i<n;++i)
        {
            fast=fast->next;
            if(fast==NULL)
                return NULL;
        }
        
        while(fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        
        ListNode *temp=slow->next;
        slow->next=slow->next->next;
        delete temp;
        
        return dummy.next;
    }
};
