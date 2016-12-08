解题思路：
最直接的思路是将链表反转，然后按序输出
反转链表有递归与非递归两种方式
但打印只是一个只读操作，最好不要破坏链表的结构，有以下几种解法
1.利用栈后进先出的原理，即可将链表逆序输出
2.使用递归
3.依次将链表中各结点的值insert到vector头，原理同stack
4.依次将链表中各结点的值push_back到vector中，再reverse一下即可
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
//解法1
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;

		if (head == NULL)
			return result;

		stack<ListNode *> stack;
		ListNode *node = head;
		while (node)
		{
			stack.push(node);
			node = node->next;
		}

		while (!stack.empty())
		{
			node = stack.top();
			result.push_back(node->val);
			stack.pop();
		}

		return result;
	}
};
//解法2
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;
		ListNode *node = head;

		if (node)
		{
			result.insert(result.begin(), node->val);
			if (node->next)
			{
				vector<int> tempVec = printListFromTailToHead(node->next);
				if (tempVec.size() > 0)
					result.insert(result.begin(), tempVec.begin(), tempVec.end());
			}
		}

		return result;
	}
};
//解法3
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;
		ListNode *node = head;

		if (node)
		{
			result.insert(result.begin(), node->val);
			while (node->next)
			{
				result.insert(result.begin(), node->next->val);
				node = node->next;
			}
		}

		return result;
	}
};
//解法4
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;
		ListNode *node = head;

		while (node)
		{
			result.push_back(node->val);
			node = node->next;
		}
		reverse(result.begin(), result.end());

		return result;
	}
};
