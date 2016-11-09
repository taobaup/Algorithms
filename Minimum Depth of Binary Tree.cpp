//Minimum Depth of Binary Tree
//必须对叶子节点进行判断
//当一个节点只有左子树或右子树
//不能取min(left，right)，因其为0
//只有在叶子节点才能判断深度
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
    int minDepth(TreeNode* root) {
        return minDepth(root,false);
    }
    
    int minDepth(TreeNode *root,bool hasbrother)
    {
        if(root==NULL)
            return hasbrother?INT_MAX:0;
            
        int left=minDepth(root->left,root->right!=NULL);
        int right=minDepth(root->right,root->left!=NULL);
        
        return min(left,right)+1;
    }
};
