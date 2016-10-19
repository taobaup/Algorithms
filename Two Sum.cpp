//借助哈希表，保存数组中每个数的下标
//遍历数组的同时在哈希表中查找即可
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> result;
        for(int i=0;i<nums.size();++i)
            map[nums[i]]=i;
        for(int i=0;i<nums.size();++i)
        {
            int temp=target-nums[i];
            if(map.find(temp)!=map.end()&&map[temp]>i)
            {
                result.push_back(i);
                result.push_back(map[temp]);
                break;
            }
        }
        
        return result;
    }
};
