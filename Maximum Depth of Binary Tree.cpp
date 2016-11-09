//Maximum Depth of Binary Tree
//二叉树的深度为其左、右子树的深度加1
//时间复杂度 O(n)，空间复杂度 O(logn)
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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
            
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        
        return max(left,right)+1;
    }
};
