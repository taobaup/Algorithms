

英文链接: https://leetcode.com/problems/implement-trie-prefix-tree/  
中文链接: https://leetcode-cn.com/problems/implement-trie-prefix-tree/

```
class TrieNode {
public:
	TrieNode *child[26];
	bool isWord;

	TrieNode() : isWord(false)
	{
		for (auto &s : child)
		{
			s = NULL;
		}
	}
};

class Trie {
private:
	TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;

        for (auto &s : word)
        {
        	int i = s - 'a';
        	if (p->child[i] == NULL)
        	{
        		p->child[i] = new TrieNode();
        	}

        	p = p->child[i];
        }

        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;

        for (auto &s : word)
        {
        	int i = s - 'a';
        	if (p->child[i] == NULL)
        	{
        		return false;
        	}

        	p = p->child[i];
        }

        // 不要写成 return true;
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;

        for (auto &s : prefix)
        {
        	int i = s - 'a';
        	if (p->child[i] == NULL)
        	{
        		return false;
        	}

        	p = p->child[i];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
```
