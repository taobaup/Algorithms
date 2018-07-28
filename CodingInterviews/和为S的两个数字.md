>和为S的两个数字

// 左右夹逼，因为 (a+1)(b-1) > ab
// 所以最先找到的两数乘积必然最小
// 注意返回的是两数字而不是小标


```
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    	vector<int> result;
        int len = array.size();
        if(len <= 1)
        	return result;

        int i = 0;
        int j = len - 1;
        while(i < j)
        {
        	if(array[i] + array[j] == sum)
        	{
        		result.push_back(array[i]);
        		result.push_back(array[j]);
        		break;
        	}
        	else if(array[i] + array[j] < sum)
        		++i;
        	else
        		--j;
        }

        return result;
    }
};
```
