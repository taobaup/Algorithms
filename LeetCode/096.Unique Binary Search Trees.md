英文链接: https://leetcode.com/problems/unique-binary-search-trees/  
中文链接: https://leetcode-cn.com/problems/unique-binary-search-trees/


| Status	| Runtime	| Language  
| ------ | ------ | ------ 
| Memory Limit Exceeded	| N/A	| cpp

```
class Solution {
public:
    int numTrees(int n) {
        vector<TreeNode *> res;
        int count = 0;
        
        if (n == 0) 
            return count;
        
        res = *generateTreesDFS(1, n);

        count = res.size();
        return count;
    }

private:
    vector<TreeNode*> *generateTreesDFS(int start, int end) 
    {
        vector<TreeNode*> *subTree = new vector<TreeNode*>();
        if (start > end) 
        {
            subTree->push_back(NULL);
        }
        else 
        {
            for (int i = start; i <= end; ++i) 
            {
                vector<TreeNode*> *leftSubTree = generateTreesDFS(start, i - 1);
                vector<TreeNode*> *rightSubTree = generateTreesDFS(i + 1, end);

                for (int j = 0; j < leftSubTree->size(); ++j) 
                {
                    for (int k = 0; k < rightSubTree->size(); ++k) 
                    {
                        TreeNode *node = new TreeNode(i);
                        node->left = (*leftSubTree)[j];
                        node->right = (*rightSubTree)[k];

                        subTree->push_back(node);
                    }
                }
            }
        }

        return subTree;
    }
};
```


```
  1                        n = 1

                2        1                   n = 2
               /          \
              1            2
  
   1         3     3      2      1           n = 3
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

```
n分别为1,2,3

dp[2]=dp[0]*dp[1]　　　(1为根的情况)

　　　+dp[1]*dp[0]　 (2为根的情况)


dp[3]=dp[0]*dp[2]　　  (1为根的情况)

　　　+dp[1]*dp[1]　 (2为根的情况)

 　　 +dp[2]*dp[0]　 (3为根的情况)
```

```
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                // 不要把 * 写成 +
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};
```
