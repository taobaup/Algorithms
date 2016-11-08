//Binary Tree Inorder Traversal
//借助栈，遍历二叉树
//先让所有的左孩子结点入栈
//再将右孩子结点入栈
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<const TreeNode*> s;
        const TreeNode *cur=root;
        
        while(cur||!s.empty())
        {
            if(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            else
            {
                cur=s.top();
                s.pop();
                result.push_back(cur->val);
                cur=cur->right;
            }
        }
        
        return result;
    }
};
