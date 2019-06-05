英文链接: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/  
中文链接: https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/

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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;

		level(result, root, 1);
		reverse(result.begin(), result.end());

		return result;
	}

private:
	void level(vector<vector<int>> &result, TreeNode *root, int num)
	{
		if (root == NULL)
		{
			return;
		}

		if (result.size() < num)
		{
			result.push_back(vector<int>());
		}

		result[num - 1].push_back(root->val);
		level(result, root->left, num + 1);
		level(result, root->right, num + 1);
	}
};
```

```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        level(result, root, 1);
        
        return vector<vector<int>>(result.rbegin(), result.rend());
    }
    
    void level(vector<vector<int>> &result, TreeNode *root, int num)
    {
        if(root == NULL)
        {
            return;
        }

        if(result.size() < num)
        {
            result.push_back(vector<int>());
        }
            
        result[num - 1].push_back(root->val);
        level(result, root->left, num + 1);
        level(result, root->right, num + 1);
    }
};
```

```
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;

		if (root == NULL)
		{
			return res;
		}

		queue<const TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			vector<int> level;
			int len = q.size();

			for (int i = 0; i < len; ++i)
			{
				const TreeNode *node = q.front();
				q.pop();

				level.push_back(node->val);

				if (node->left != NULL)
				{
					q.push(node->left);
				}
				// 不要写成 else if 
				if (node->right != NULL)
				{
					q.push(node->right);
				}
			}

			res.insert(res.begin(), level);
		}

		return res;
	}
};
```

```
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;

		if (root == NULL)
		{
			return res;
		}

		queue<const TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			vector<int> level;
			int len = q.size();

			for (int i = 0; i < len; ++i)
			{
				const TreeNode *node = q.front();
				q.pop();

				level.push_back(node->val);

				if (node->left != NULL)
				{
					q.push(node->left);
				}
				
				// 不要写成 else if 
				if (node->right != NULL)
				{
					q.push(node->right);
				}		
			}

			res.push_back(level);
		}

		reverse(res.begin(), res.end());

		return res;
	}
};
```
