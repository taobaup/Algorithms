// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();

        if(len == 0)
            return NULL;

        ListNode *cur = lists[0];
        for(int i = 1; i < len; ++i)
        {
            cur = mergeTwoListsIterative(cur, lists[i]);
            // cur = mergeTwoListsRecursive(cur, lists[i]);
        }

        return cur;
    }

    // 注意 cur->next = l1; 不要写成 cur->next = l1->next;
    // cur->next = l2; 不要写成 cur->next = l2->next;
    // 不要遗漏 cur = cur->next;
    ListNode* mergeTwoListsIterative(ListNode *l1, ListNode *l2) {
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

    ListNode* mergeTwoListsRecursive(ListNode *l1, ListNode *l2) {
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
            l2->next = mergeTwoListsRecursive(l1, l2->next);
            return l2;
        }
    }
    
};




2)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();

        if(len == 0)
            return NULL;

        return mergeKListsRecursive(lists, 0, len - 1);
    }

    ListNode* mergeKListsRecursive(vector<ListNode*>& lists, int left, int right)
    {
        if(left == right)
            return lists[left];
        else if(left < right)
        {
            int mid = left + (right - left) / 2;
            ListNode *l = mergeKListsRecursive(lists, left, mid);
            ListNode *r = mergeKListsRecursive(lists, mid + 1, right);
            return mergeTwoListsIterative(l, r);
            // return mergeTwoListsRecursive(l, r);
        }
        else
            return NULL;
    }

    // 注意 cur->next = l1; 不要写成 cur->next = l1->next;
    // cur->next = l2; 不要写成 cur->next = l2->next;
    // 不要遗漏 cur = cur->next;
    ListNode* mergeTwoListsIterative(ListNode *l1, ListNode *l2) {
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

    ListNode* mergeTwoListsRecursive(ListNode *l1, ListNode *l2) {
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
            l2->next = mergeTwoListsRecursive(l1, l2->next);
            return l2;
        }
    }
    
};




3)
// 不要遗漏 operator 后面的 () 以及 struct 最后的；
struct cmp
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len <= 0)
            return NULL;

        priority_queue<ListNode*, vector<ListNode*>, cmp>  q;
        // 注意一定要判断 lists[i] != NULL
        // 否则后面会出错的
        for(int i = 0; i < len; ++i)
        {
            if(lists[i] != NULL)
            {
                q.push(lists[i]);
            }
                
        }

        ListNode *head = NULL;
        ListNode *prev = NULL;
        ListNode *temp = NULL;

        while(!q.empty())
        {
            temp = q.top();
            q.pop();

            if(prev == NULL)
                head = temp;
            else
                prev->next = temp;

            // prev可能为 NULL 所以不能写 prev = prev->next;
            prev = temp;
            // push前一定要判断 lists[i] != NULL
            if(temp->next != NULL)
                q.push(temp->next);
        }
        
        return head;
    }
};
