//Binary Tree Preorder Traversal
//借助栈，遍历二叉树
//先让根结点入栈
//再将右、左孩子结点入栈
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<const TreeNode*> s;
        const TreeNode *cur=root;
        
        if(cur)
            s.push(cur);
        while(!s.empty())
        {
            cur=s.top();
            s.pop();
            result.push_back(cur->val);
            
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
        }
        
        return result;
    }
};
