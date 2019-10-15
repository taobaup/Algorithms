英文链接: https://leetcode.com/problems/clone-graph/  
中文链接: https://leetcode-cn.com/problems/clone-graph/

```
// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
```



```
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		unordered_map<int, UndirectedGraphNode*> umap;
		return clone(node, umap);
	}

	UndirectedGraphNode *clone(UndirectedGraphNode *node, unordered_map<int,
			UndirectedGraphNode*> &umap) 
	{
		if (node == NULL) 
		{
			return node;
		}

		if (umap.count(node->label) > 0) 
		{
			return umap[node->label];
		}

		UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
		umap[node->label] = newNode;
		for (int i = 0; i < node->neighbors.size(); ++i) 
		{
			(newNode->neighbors).push_back(clone(node->neighbors[i], umap));
		}

		return newNode;
	}
};
```
