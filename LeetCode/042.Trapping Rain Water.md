1:
class Solution {
public:
    int trap(vector<int>& height) {
    	int res = 0;
        const int len = height.size();
        if(len <= 0)
        	return res;

        // not  int *left = new int[len];
        int *left = new int[len]();
        int *right = new int[len]();
        for(int i = 1; i < len; ++i)
        	left[i] = max(left[i - 1], height[i - 1]);

        for(int i = len - 2; i >= 0; --i)
        	right[i] = max(right[i + 1], height[i + 1]);

        for(int i = 0; i < len; ++i)
        {
        	int value = min(left[i], right[i]);
        	if(value > height[i])
        		res += value- height[i];
        }

        delete[] left;
        delete[] right;

        return res;
    }
};




2:
class Solution {
public:
    int trap(vector<int>& height) {
    	int res = 0;
    	const int len = height.size();
    	if(len <= 0)
    		return res;

    	int l = 0;
    	int r = len - 1;
    	while(l < r)
    	{
    		int minH = min(height[l], height[r]);

    		if(height[l] == minH)
    		{
    			++l;

    			// not height[l] > minH
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
