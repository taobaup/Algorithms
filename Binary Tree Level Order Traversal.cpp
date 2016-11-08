//Binary Tree Level Order Traversal
//借助vector<vector<int>>跟num
//依次插入各层
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        level(result,root,1);
        
        return result;
    }
    
    void level(vector<vector<int>> &result,TreeNode *root,int num)
    {
        if(root==NULL)
            return;
        if(num>result.size())
            result.push_back(vector<int>());
            
        result[num-1].push_back(root->val);
        level(result,root->left,num+1);
        level(result,root->right,num+1);
    }
};
