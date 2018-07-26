1:
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int *left = new int[n]();
        int *right = new int[n]();
        int sum = 0;

        for(int i = 1; i < n; ++i)
            left[i] = max(left[i-1], height[i-1]);
        for(int i = n - 2; i >= 0; --i)
            right[i] = max(right[i+1], height[i+1]);

        for(int i = 0; i < n; ++i)
        {
            int value = min(left[i], right[i]);
            if(value > height[i])
                sum += value - height[i];
        }

        delete[] left;
        delete[] right;

        return sum;
    }
};




2:
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len == 0)
            return 0;

        int l = 0;
        int r = len - 1;
        int res = 0;

        while(l < r)
        {
            int minH = min(height[l], height[r]);
            if(height[l] == minH)
            {
                ++l;
                while(l < r && height[l] < minH)
                {
                    res += minH - height[l];
                    ++l;
                }
            }
            else
            {
                --r;
                while(l < r && height[r] < minH)
                {
                    res += minH - height[r];
                    --r;
                }
            }
        }

        return res;
    }
};
