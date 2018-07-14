class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)
        	return x;

        int res = 0;
        int left = 1;
        int right = x / 2;
        while(left <= right)
        {
        	int mid = left + ((right - left) >> 1);
        	if(x / mid > mid)
        	{
        		left = mid + 1;
        		res = mid;
        	}
        	else if(x / mid < mid)
        	{
        		right = mid - 1;
        	}
        	else
        		return mid;
        } 

        return res;
    }
};
