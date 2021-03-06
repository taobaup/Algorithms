英文链接: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/  
中文链接: https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


```
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```
```
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(begin(inorder), end(inorder), begin(postorder), end(postorder));
    }

    template<typename MyIt>
    TreeNode* buildTree(MyIt in_first, MyIt in_last, MyIt pos_first, MyIt pos_last) {
        if(in_first == in_last)
            return NULL;

        if(pos_first == pos_last)
            return NULL;

        const int value = *prev(pos_last);
        MyIt in_mid = find(in_first, in_last, value);
        int len = distance(in_first, in_mid);
        MyIt pos_mid = next(pos_first, len);

        TreeNode *root = new TreeNode(value);
        root->left = buildTree(in_first, in_mid, pos_first, pos_mid);
        // 特别注意范围
        // 尤其是 pos_mid, prev(pos_last) 不要写成 next(pos_mid), pos_last 等
        root->right = buildTree(next(in_mid), in_last, pos_mid, prev(pos_last));

        return root;
    }
};
```
