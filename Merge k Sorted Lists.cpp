//Merge k Sorted Lists
//复用Merge Two Sorted Lists即可，解法分迭代版和递归版两种
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
//迭代版
//时间复杂度为O(n1+n2+…)，空间复杂度为O(1)
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
            return NULL;
        
        ListNode *p=lists[0];
        for(int i=1;i<lists.size();++i)
            p=mergeTwoLists(p,lists[i]);
            
        return p;
    }
    
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
            return NULL;
        
        ListNode *p=lists[0];
        for(int i=1;i<lists.size();++i)
            p=mergeTwoLists(p,lists[i]);
            
        return p;
    }
    
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
