class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		for (int i = 0; i + 1 < prices.size(); ++i)
			result += max(0, prices[i + 1] - prices[i]);
		return result;
	}
};