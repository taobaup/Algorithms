

英文链接: https://leetcode.com/problems/search-a-2d-matrix/  
中文链接: https://leetcode-cn.com/problems/search-a-2d-matrix/


>编写一个搜索m*n矩阵中的值的有效算法，该矩阵具有以下性质：   
每行中的整数从左到右排序。   
每行的第一个整数大于前一行的最后一个整数。



1：给定矩阵是有序的，可以采用两次二分查找，先找出行，再找出列   
2：将该矩阵看成是一个一维数组，数组值为 matrix[ i / n ][ i % n ]

```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m <= 0)
        	return false;
        int n = matrix[0].size();
        if(n <= 0)
        	return false;

        // 注意先判断 target 是否处于数组范围内
        if(target < matrix[0][0] || target > matrix[m - 1][n - 1])
        	return false;

        int l = 0;
        int r = m - 1;
        while(l <= r)
        {
        	int mid = l + ((r - l) >> 1);
        	// 注意是先用第一列来判断行数，不要写成 matrix[mid]
        	if(target == matrix[mid][0])
        		return true;
        	else if(target < matrix[mid][0])
        		r = mid - 1;
        	else
        		l = mid + 1;
        }

        int ll = 0;
        int rr = n - 1;
        while(ll <= rr)
        {
        	int lmid = ll + ((rr - ll) >> 1);
        	// matrix[r][lmid] 不要选错范围
        	if(target == matrix[r][lmid])
        		return true;
        	else if(target < matrix[r][lmid])
        		rr = lmid - 1;
        	else
        		ll = lmid + 1;
        }

        return false;
    }
};
```



```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int m = matrix.size();
    	if(m <= 0)
    		return false;
    	int n = matrix[0].size();
    	if(n <= 0)
    		return false;

    	// 一定不要遗漏这一步
    	if(target < matrix[0][0] || target > matrix[m - 1][n - 1])
    		return false;

    	int left = 0;
    	int right = m * n - 1;
    	// 注意 matrix[mid / n][mid % n] 下标不要选错
    	while(left <= right)
    	{
    		int mid = left + ((right - left) >> 1);
    		if(target == matrix[mid / n][mid % n])
    			return true;
    		else if(target < matrix[mid / n][mid % n])
    			right = mid - 1;
    		else
    			left = mid + 1;
    	}

    	return false;
    }
};
```
