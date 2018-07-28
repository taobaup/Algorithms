>输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:对应每个测试案例，输出两个数，小的先输出。

左右夹逼，因为 (a+1)(b-1) > ab，所以最先找到的两数乘积必然最小，注意返回的是两数字而不是小标


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
