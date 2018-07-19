// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 二叉树的深度为其左、右子树的深度加1
1）
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};




2）
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1; 
    }
};




3）
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty())
        {
            ++level;

            int len = q.size();
            for(int i = 0; i < len; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }

        return level;
    }
};
