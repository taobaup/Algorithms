英文链接: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/  
中文链接: https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/

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
     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        level(result, root, 1, true);
        
        return result;
    }
    
private:
    void level(vector<vector<int>> &result, TreeNode *root, int num, bool flag)
    {
        if(root == NULL)
        {
            return;
        }

        if(result.size() < num)
        {
            result.push_back(vector<int>());
        }
            
        if(flag)
        {
            result[num - 1].push_back(root->val);
        }
        else
        {
            result[num - 1].insert(result[num - 1].begin(), root->val);
        }

        level(result, root->left, num + 1, !flag);
        level(result, root->right, num + 1, !flag);
    }
};
```

```
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == NULL) 
        {
            return res;
        }

        stack<TreeNode*> s1, s2;
        s1.push(root);
        vector<int> out;

        while (!s1.empty() || !s2.empty()) 
        {
            while (!s1.empty()) 
            {
                TreeNode *cur = s1.top();
                s1.pop();
                out.push_back(cur->val);

                if (cur->left != NULL) 
                {
                    s2.push(cur->left);
                }

                if (cur->right != NULL) 
                {
                    s2.push(cur->right);
                }
            }

            if (!out.empty()) 
            {
                res.push_back(out);
            }
            out.clear();

            while (!s2.empty()) 
            {
                TreeNode *cur = s2.top();
                s2.pop();
                out.push_back(cur->val);

                if (cur->right != NULL) 
                {
                    s1.push(cur->right);
                }

                if (cur->left != NULL) 
                {
                    s1.push(cur->left);
                }
            }

            if (!out.empty()) 
            {
                res.push_back(out);
            }
            out.clear();
        }
        
        return res;
    }
};
```

```
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;

		if (root == NULL)
		{
			return res;
		}

		queue<const TreeNode*> q;
		q.push(root);

        	int count = 0;
		while (!q.empty())
		{
			vector<int> level;
			int len = q.size();

            		count += 1;
			for (int i = 0; i < len; ++i)
			{
				const TreeNode *node = q.front();
				q.pop();

				level.push_back(node->val);

				if (node->left != NULL)
				{
					q.push(node->left);
				}
				
                		// 这里一定不要写成 else if
                		if (node->right != NULL)
				{
					q.push(node->right);
				}
			}
            
            		if (count % 2 == 0)
            		{
                		reverse(level.begin(), level.end());
            		}

			// 不要遗漏这一步
			res.push_back(level);
		}

		return res;
	}
};
```
