1　　(2)　　7　　4　　3　　1

1　　2　　7　　4　　(3)　　1

1　　(3)　　7　　4　　(2)　　1

1　　3　　[1　　2　　4　　7]


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
        
        reverse(nums.begin() + i + 1, nums.end());
    }
};
