英文链接: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/  
中文链接: https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
        if(root == NULL)
        {
            return;
        }
        
        vector<TreeNode *> res;
        preorder(res, root);
        tobelist(res, root);
    }

private:
    void preorder(vector<TreeNode *> &res, TreeNode *root) {
        if(root == NULL)
        {
            return;
        }

        res.push_back(root);
        preorder(res, root->left);
        preorder(res, root->right);
    }

    void tobelist(vector<TreeNode *> &res, TreeNode *root)
    {
    	if(res.empty())
    	{
    		return;
    	}

    	root = res[0];
        for(int i = 1; i < res.size(); ++i)
        {
        	root->left = NULL;
        	root->right = res[i];
        	root = root->right;
        }
    }
};

```


```
class Solution {
public:
    void flatten(TreeNode* root) {
    	if(root == NULL)
        {
            return;
        }

        vector<TreeNode*> res;
        preorder(res, root);
        tobelist(res, root);
    }

private:
    void preorder(vector<TreeNode *> &res, TreeNode *root) {
        stack<TreeNode*> s;
        TreeNode *p = root;

        while(!s.empty() || p != NULL)
        {
            if(p != NULL)
            {
                s.push(p);
                res.push_back(p);
                p = p->left;
            }
            else
            {
                TreeNode *t = s.top();
                s.pop();
                p = t->right;
            }
        }
    }

    void tobelist(vector<TreeNode *> &res, TreeNode *root)
    {
    	if(res.empty())
    	{
    		return;
    	}

    	root = res[0];
        for(int i = 1; i < res.size(); ++i)
        {
        	root->left = NULL;
        	root->right = res[i];
        	root = root->right;
        }
    }
};

```
