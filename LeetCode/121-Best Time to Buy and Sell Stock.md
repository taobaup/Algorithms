英文链接: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/  
中文链接: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

最多只允许完成一笔交易（即买入和卖出一支股票）

```
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
		{
			return 0;
		}

		// profit 不为负数，所以 profit 初始值不能为 INT_MIN
		int profit = 0;
		int cur_min = prices[0];
		for (int i = 1; i < prices.size(); ++i)
		{
			profit = max(profit, prices[i] - cur_min);
			cur_min = min(cur_min, prices[i]);
		}

		return profit;
	}
};
```
