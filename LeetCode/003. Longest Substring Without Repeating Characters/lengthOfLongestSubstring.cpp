1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256] = {0};
        int res = 0, left = 0;

        for(int i = 0; i < s.size(); ++i)
        {
        	if(m[s[i]] == 0 || m[s[i]] < left)
        		res = max(res, i - left + 1);
        	else
        		left = m[s[i]];

        	// 不要误写成 ++m[s[i]];
        	m[s[i]] = i + 1;
        }

        return res;
    }
};


2)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(256, -1);
        int res = 0;
        int left = -1;

        for(int i = 0; i < s.size(); ++i)
        {
        	left = max(left, m[s[i]]);
        	res = max(res, i - left);
        	m[s[i]] = i;
        }

        return res;
    }
};
