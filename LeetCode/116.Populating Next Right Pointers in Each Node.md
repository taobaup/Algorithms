英文链接: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/  
中文链接: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/

```
// Definition for binary tree with next pointer.
struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
```


```
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) 
        {
            return;
        }

        if (root->left != NULL) 
        {
            root->left->next = root->right;
        }

        if (root->right != NULL) 
        {
            root->right->next = root->next? root->next->left : NULL;
        }

        connect(root->left);
        connect(root->right);
    }
};
```


```
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) 
        {
            return;
        }
        
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) 
        {
            int len = q.size();
            for (int i = 0; i < len; ++i) 
            {
                TreeLinkNode *t = q.front(); 
                q.pop();

                if (i < len - 1) 
                {
                    t->next = q.front();
                }

                if (t->left != NULL) 
                {
                    q.push(t->left);
                }

                if (t->right != NULL) 
                {
                    q.push(t->right);
                }
            }
        }
    }
};
```



```
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode dummy(INT_MIN);
        TreeLinkNode *t = &dummy;
        
        while (root != NULL) 
        {
            if (root->left != NULL) 
            {
                t->next = root->left;
                t = t->next;
            }

            if (root->right != NULL) 
            {
                t->next = root->right;
                t = t->next;
            }

            root = root->next;
            if (root == NULL) 
            {
                t = &dummy;
                root = dummy.next;
                dummy.next = NULL;
            }
        }
    }
};
```
