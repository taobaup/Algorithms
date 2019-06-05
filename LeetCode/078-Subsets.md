英文链接: https://leetcode.com/problems/subsets/  
中文链接: https://leetcode-cn.com/problems/subsets/


```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> out;

        sort(nums.begin(), nums.end());
        getSubsets(nums, 0, out, res);

        return res;
    }

    void getSubsets(vector<int> &nums, int pos, vector<int> &out, vector<vector<int>> &res) 
    {
        res.push_back(out);

        for (int i = pos; i < nums.size(); ++i) 
        {
            out.push_back(nums[i]);
            getSubsets(nums, i + 1, out, res);
            out.pop_back();
        }
    }
};
```
