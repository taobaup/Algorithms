英文链接: https://leetcode.com/problems/minimum-depth-of-binary-tree/  
中文链接: https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

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
	int minDepth(TreeNode *root) {
		if (root == NULL) 
		{
			return 0;
		}

		if (root->left == NULL && root->right == NULL) 
		{
			return 1;
		}

		if (root->left == NULL) 
		{
			return minDepth(root->right) + 1;
		}
		else if (root->right == NULL) 
		{
			return minDepth(root->left) + 1;
		}
		else 
		{
			return 1 + min(minDepth(root->left), minDepth(root->right));
		}
	}
};
```



```
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0;
        while(!q.empty())
        {
            ++level;

            int len = q.size();
            for(int i = 0; i < len; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                if(node->left == NULL && node->right == NULL)
                {
                    return level;
                }

                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                if(node->right != NULL)
                {
                    q.push(node->right);
                }
            }
        }

        return level;
    }
};
```
