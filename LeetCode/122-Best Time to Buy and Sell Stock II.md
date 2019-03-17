英文链接: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/  
中文链接: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

可以尽可能地完成更多的交易（多次买卖一支股票）

```
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		if (prices.empty())
		{
			return profit;
		}

		for (int i = 1; i < prices.size(); ++i)
		{
			int diff = prices[i] - prices[i - 1];
			if (diff > 0)
			{
				profit += diff;
			}
		}

		return profit;
	}
};
```
