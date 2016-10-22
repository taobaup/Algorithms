//Trapping Rain Water
//从左到右遍历数组，找出每个i的maxleft
//从右到左遍历数组，找出每个i的maxright
//若min(maxleft,maxright)大于i的高度，则其差值为i的蓄水量
class Solution {
public:
    int trap(vector<int>& height) {
        const int n=height.size();
        int *left=new int[n]();
        int *right=new int[n]();
        int sum=0;
        
        for(int i=1;i<n;++i)
            left[i]=max(left[i-1],height[i-1]);
        for(int i=n-2;i>=0;--i)
            right[i]=max(right[i+1],height[i+1]);
        
        for(int i=0;i<n;++i)
        {
            int value=min(left[i],right[i]);
            if(value>height[i])
                sum+=value-height[i];
        }
        
        delete[] left;
        delete[] right;
        
        return sum;
    }
};
