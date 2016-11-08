//Binary Tree Postorder Traversal
//借助栈，遍历二叉树
//先让所有的左孩子结点入栈
//再将右孩子结点入栈
//根结点出栈时，比如检测右孩子结点是否已被访问或不存在
//若未被访问，根结点必须重新入栈（因后序遍历应先打印右孩子结点的值）
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<const TreeNode*> s;
        const TreeNode *cur,*prev;
        
        cur=root;
        do
        {
            while(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            prev=NULL;
            while(!s.empty())
            {
                cur=s.top();
                s.pop();
                if(cur->right==prev)
                {
                    result.push_back(cur->val);
                    prev=cur;
                }
                else
                {
                    s.push(cur);
                    cur=cur->right;
                    break;
                }
            }
        }while(!s.empty());
        
        return result;
    }
};
