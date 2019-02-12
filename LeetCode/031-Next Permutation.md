英文链接: https://leetcode.com/problems/next-permutation/  
中文链接: https://leetcode-cn.com/problems/next-permutation/


```
1　　(2)　　7　　4　　3　　1

1　　2　　7　　4　　(3)　　1

1　　(3)　　7　　4　　(2)　　1

1　　3　　[1　　2　　4　　7]

如果给定数组是降序，则说明是全排列的最后一种情况 
则下一个排列就是最初始情况，直接reverse即可 
否则如下所示   
1　　2　　7　　4　　3　　1 
从后到前遍历数组，找出第一个降序的数字2 
再从后到前遍历一次数组，找出第一个比2大的数3 
交换3跟2，得到   
1　　3　　7　　4　　2　　1 
再把[原来2的位置即现在3的位置的后1位，到尾元素]的数字段反转，得到  
1　　3　　1　　2　　4　　7
```


```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();

        int i = len - 2;
        while(i >= 0 && nums[i] >= nums[i + 1])
            --i;

        if(i >= 0)
        {
            int j = len - 1;
            while(i < j)
            {
                if(nums[i] < nums[j])
                    break;
                --j;
            }

            swap(nums[i], nums[j]);
        }
        
        // reverse, not nums.reverse
        reverse(nums.begin() + i + 1, nums.end());
    }
};
```
