英文链接: https://leetcode.com/problems/linked-list-cycle/  
中文链接: https://leetcode-cn.com/problems/linked-list-cycle/


>给定一个链表，判断其是否有环(不使用额外空间)   
若不考虑空间复杂度，则可借助指针数组或哈希表   
判断链表结点是否重新出现   
若不使用额外空间，则应使用快慢指针   
若快慢指针相遇，则证明有环   
时间复杂度为O(n)，空间复杂度为O(1)


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
    bool hasCycle(ListNode *head) {
    	bool hasCycle = false;

    	ListNode *fast = head;
    	ListNode *slow = head;

    	while(fast != NULL && fast->next != NULL)
    	{
    		fast = fast->next->next;
    		slow = slow->next;

    		if(fast == slow)
    		{
    			hasCycle = true;
    			break;
    		}
    	}      

    	return hasCycle;
    }
};
```
