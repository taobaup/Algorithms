1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m < 0 || n < 0)
            return;

        int len = m + n;
        int *total = new int[len];

        int i = 0, j = 0, k = 0;
        while(i < m && j <n)
        {
            if(nums1[i] <= nums2[j])
            {
                total[k++] = nums1[i++];
            }
            else
            {
                total[k++] = nums2[j++];
            }
        }

        while(i < m)
        {
            total[k++] = nums1[i++];
        }
        while(j < n)
        {
            total[k++] = nums2[j++];
        }
    
        for(int p = 0; p < len; ++p)
            nums1[p] = total[p];
    }
};




2)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m < 0 || n < 0)
            return;

        int k = m + n - 1;
        --m;
        --n;
       
        while(m >= 0 && n >= 0)
        {
            if(nums1[m] > nums2[n])
                nums1[k--] = nums1[m--];
            else
                nums1[k--] = nums2[n--];
        }

        while(n >= 0)
            nums1[k--] = nums2[n--];

        return;
    }
};
