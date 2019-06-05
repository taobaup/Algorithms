英文链接: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/  
中文链接: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/


递归的解法: 这里由于子树有可能残缺，故需要平行扫描父节点同层的节点，找到他们的左右子节点


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
        
        TreeLinkNode *p = root->next;
        while (p != NULL) 
        {
            if (p->left != NULL) 
            {
                p = p->left;
                break;
            }

            if (p->right != NULL) 
            {
                p = p->right;
                break;
            }

            p = p->next;
        }

        if (root->right != NULL) 
        {
            root->right->next = p;
        }

        if (root->left != NULL) 
        {
            root->left->next = root->right ? root->right : p;
        }

        connect(root->right);
        connect(root->left);
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
