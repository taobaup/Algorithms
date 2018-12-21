英文链接: https://leetcode.com/problems/recover-binary-search-tree/  
中文链接: https://leetcode-cn.com/problems/recover-binary-search-tree/

```
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```



A solution using O(n) space is pretty straight forward.  
使用O(n)空间的解决方案非常直接

```
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int> nums;

        inorder(list, nums, root);

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i)
            list[i]->val = nums[i];

        return;
    }

private:
    void inorder(vector<TreeNode*> &list, vector<int> &nums, TreeNode *root) {
        if(root == NULL)
            return;

        inorder(list, nums, root->left);
        list.push_back(root);
        nums.push_back(root->val);
        inorder(list, nums, root->right);
    }
};
```

```
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int> nums;

        inorderTraversal(list, nums, root);

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i)
            list[i]->val = nums[i];

        return;
    }

private:
    void inorderTraversal(vector<TreeNode*> &list, vector<int> &nums, TreeNode *root) {
        if(root == NULL)
            return;

        stack<TreeNode*> s;
        TreeNode *p = root;

        while(!s.empty() || p != NULL)
        {
            if(p != NULL)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                TreeNode *t = s.top();
                s.pop();

                nums.push_back(t->val);
                list.push_back(t);
                p = t->right;
            }
        }
    }
};
```
