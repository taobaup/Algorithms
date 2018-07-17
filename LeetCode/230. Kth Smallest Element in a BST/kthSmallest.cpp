// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    	if(root == NULL || k == 0)
    		return NULL;

    	TreeNode *res = kthSmallestCore(root, k);   
    	return res->val;
    }

    TreeNode* kthSmallestCore(TreeNode* root, int &k) {
        TreeNode *res = NULL;

        if(root->left != NULL)
        	res = kthSmallestCore(root->left, k);

        if(res == NULL)
       	{
       		if(k == 1)
       			res = root;

       		--k;
       	}

       	if(res ==NULL && root->right != NULL)
       		res = kthSmallestCore(root->right, k);

       	return res;
    }
};
