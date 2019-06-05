英文链接: https://leetcode.com/problems/invert-binary-tree/  
中文链接: https://leetcode-cn.com/problems/invert-binary-tree/

```
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
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
		{
			return NULL;
		}

		TreeNode *tmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tmp);

		return root;
	}
};
```

```
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
		{
			return NULL;
		}

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode *node = q.front();
			q.pop();

			TreeNode *tmp = node->left;
			node->left = node->right;
			node->right = tmp;

			if (node->left)
			{
				q.push(node->left);
			}

			if (node->right)
			{
				q.push(node->right);
			}
		}

		return root;
	}
};
```
