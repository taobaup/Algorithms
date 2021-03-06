英文链接: https://leetcode.com/problems/binary-tree-postorder-traversal/  
中文链接: https://leetcode-cn.com/problems/binary-tree-postorder-traversal/  


```
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

```
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
		{
			return result;
		}

		postorder(result, root);

		return result;
	}

private:
	void postorder(vector<int> &result, TreeNode* root)
	{
		if (root == NULL)
		{
			return;
		}

		postorder(result, root->left);
		postorder(result, root->right);
		result.push_back(root->val);
	}
};
```

```
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;

		if (root == NULL)
		{
			return result;
		}

		stack<const TreeNode*> s;
		const TreeNode *p = root;

		while (!s.empty() || p != NULL)
		{
			if (p != NULL)
			{
				s.push(p);

				result.insert(result.begin(), p->val);

				// left, right不要写反
				p = p->right;
			}
			else
			{
				const TreeNode *t = s.top();
				s.pop();

				p = t->left;
			}
		}

		return result;
	}
};
```

```
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;

		if (root == NULL)
		{
			return result;
		}

		stack<const TreeNode*> s;
		const TreeNode *p = root;

		while (!s.empty() || p != NULL)
		{
			if (p != NULL)
			{
				s.push(p);

				result.push_back(p->val);

				// left, right不要写反
				p = p->right;
			}
			else
			{
				const TreeNode *t = s.top();
				s.pop();

				p = t->left;
			}
		}

		reverse(result.begin(), result.end());

		return result;
	}
};
```
