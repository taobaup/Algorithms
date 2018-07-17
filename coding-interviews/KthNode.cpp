struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x)	:	
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	TreeNode* KthNode(TreeNode* root, int k)
	{
		if (root == NULL || k == 0)
			return NULL;

		return KthNodeCore(root, k);
	}

	TreeNode* KthNodeCore(TreeNode* root, int &k)
	{
		TreeNode *res = NULL;
		// 不要误写成 if (root->left == NULL)
		if (root->left != NULL)
			res = KthNodeCore(root->left, k);

		if (res == NULL)
		{
			if (k == 1)
				res = root;

			--k;
		}

		if (res == NULL && root->right != NULL)
			res = KthNodeCore(root->right, k);

		return res;
	}
};
