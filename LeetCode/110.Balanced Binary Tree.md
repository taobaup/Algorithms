英文链接: https://leetcode.com/problems/balanced-binary-tree/  
中文链接: https://leetcode-cn.com/problems/balanced-binary-tree/


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
    bool isBalanced(TreeNode *root) {
        if (root == NULL) 
        {
            return true;
        }

        if (abs(getDepth(root->left) - getDepth(root->right)) > 1) 
        {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);    
    }

    int getDepth(TreeNode *root) 
    {
        if (root == NULL) 
        {
            return 0;
        }

        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
};
```


```
class Solution {
public:    
    bool isBalanced(TreeNode *root) {
        if (checkDepth(root) == -1) 
        {
            return false;
        }

        else return true;
    }

private:
    int checkDepth(TreeNode *root) 
    {
        if (root == NULL) 
        {
            return 0;
        }

        int left = checkDepth(root->left);
        if (left == -1) 
        {
            return -1;
        }

        int right = checkDepth(root->right);
        if (right == -1) 
        {
            return -1;
        }

        int diff = abs(left - right);
        if (diff > 1) 
        {
            return -1;
        }
        else 
        {
            return 1 + max(left, right);
        }
    }
};
```
