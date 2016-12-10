解题思路：取出前序遍历序列第一个结点的值，即根结点的值
在中序遍历序列中找出根结点的位置，计算distance(in_first, in_left_last)为len
则pre_left_last = next(pre_first, len + 1)
前序遍历序列中对应的左子树的前序遍历序列为next(pre_first), pre_left_last
中序遍历序列中对应的左子树的中序遍历序列为in_first, in_left_last
前序遍历序列中对应的右子树的前序遍历序列为pre_left_last, pre_last
前序遍历序列中对应的右子树的前序遍历序列为next(in_left_last), in_last
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(begin(inorder), end(inorder), begin(postorder), end(postorder));
	}

	template<typename MyIt>
	TreeNode* buildTree(MyIt in_first, MyIt in_last, MyIt post_first, MyIt post_last) {
		if (in_first == in_last)
			return nullptr;
		if (post_first == post_last)
			return nullptr;

		const int rootValue = *prev(post_last);
		auto in_left_last = find(in_first, in_last, rootValue);
		int len = distance(in_first, in_left_last);
		auto post_left_last = next(post_first, len);

		TreeNode *root = new TreeNode(rootValue);
		root->left = buildTree(in_first, in_left_last, post_first, post_left_last);
		root->right = buildTree(next(in_left_last), in_last, post_left_last, prev(post_last));

		return root;
	}

};
