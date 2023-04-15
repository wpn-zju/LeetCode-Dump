class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		vector<vector<int>> dp(prices.size() + 1, vector<int>(5, 0));
		dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = -100000;
		for (int i = 1; i <= prices.size(); ++i) {
			// no buy
			dp[i][0] = dp[i - 1][0];
			// buy 1
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
			// sell 1
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i - 1]);
			// buy 2
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i - 1]);
			// sell 2
			dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i - 1]);
            // cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << ' ' << dp[i][3] << ' ' << dp[i][4] << ' ' << endl;
		}
		return max(dp.back()[0], max(dp.back()[2], dp.back()[4]));
	}
};