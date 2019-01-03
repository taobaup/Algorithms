英文链接: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/  
中文链接: https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums, int left, int right) 
    {
        if (left > right) 
        {
            return NULL;
        }

        int mid = left + (right - left) / 2;

        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = sortedArrayToBST(nums, left, mid - 1);
        cur->right = sortedArrayToBST(nums, mid + 1, right);

        return cur;
    }
};
```
