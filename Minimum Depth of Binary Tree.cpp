//Minimum Depth of Binary Tree
//解法分递归版和迭代版两种
//递归版：必须对叶子节点进行判断
//当一个节点只有左子树或右子树
//不能取min(left，right)，因其为0
//只有在叶子节点才能判断深度
//迭代版：借助栈，只在叶子节点才能判断深度
//否则，将左右孩子节点入栈，同时深度+1
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
//递归版
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
//迭代版
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int result=INT_MAX;
        stack<pair<TreeNode*,int>> s;
        s.push(make_pair(root,1));
        
        while(!s.empty())
        {
            TreeNode *node=s.top().first;
            int depth=s.top().second;
            s.pop();
            
            if(node->left==NULL&&node->right==NULL)
                result=min(result,depth);
                
            if(node->left&&depth<result)
                s.push(make_pair(node->left,depth+1));
            if(node->right&&depth<result)
                s.push(make_pair(node->right,depth+1));
        }
        
        return result;
    }
};
