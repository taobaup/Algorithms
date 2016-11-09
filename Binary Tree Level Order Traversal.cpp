//Binary Tree Level Order Traversal
//解法分递归版和迭代版两种
//递归版：借助vector<vector<int>>跟num
//依次插入各层
//迭代版：借助两个队列，一个记录当前层，一个记录下一层
//依次插入二维vector
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归版：
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
//迭代版：
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
            return result;
           
        vector<int> level;
        queue<const TreeNode*> cur,next;
        const TreeNode *node=root;
        cur.push(node);
        
        while(!cur.empty())
        {
            while(!cur.empty())
            {
                node=cur.front();
                cur.pop();
                level.push_back(node->val);
                if(node->left)
                    next.push(node->left);
                if(node->right)
                    next.push(node->right);
            }
            result.push_back(level);
            level.clear();
            swap(cur,next);
        }
        
        return result;
    }
};
