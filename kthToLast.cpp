//查找链表中的倒数第k个结点
//给定单链表和k，找到单链表倒数第k个节点
//如2->6->8->10->null，3则输出6
//利用快慢指针，快指针先向前走k步
//接着，快慢指针同时出发
//若快指针指向倒数第1结点
//则慢指针指向倒数第k结点
//注意判断头结点的有效性，k值是否为0
//以及快指针是否还没达到第k步就已遍历完链表
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    ListNode *kthToLast(ListNode *head, int k) {
        if(head==NULL||k==0)
            return NULL;
        
        ListNode *fast=head,*slow=head;
        for(int i=0;i<k-1;++i)
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
        
        return slow;
    }
};
