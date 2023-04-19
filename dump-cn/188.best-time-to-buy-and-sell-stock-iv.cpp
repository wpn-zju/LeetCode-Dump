class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.size() < 2 || k == 0)
			return 0;
        if(k > prices.size() / 2) {
            int ans = 0;
            for(int i = 0; i < prices.size() - 1; i++) {
                if(prices[i+1] > prices[i]) ans += prices[i+1] - prices[i];
            }
            return ans;
        }
		vector<vector<int>> dp(2, vector<int>(2 * k + 1, -1000000));
        bool e = 1;
        dp[0][0] = 0;
		dp[0][1] = -prices[0];
		for (int i = 1; i <= prices.size(); ++i) {
			// no buy
			dp[e][0] = dp[!e][0];
            int up = min(i + 1 / 2, k);
			for (int j = 0; j < up; ++j) {
				// buy k
				dp[e][2 * j + 1] = max(dp[!e][2 * j + 1], dp[!e][2 * j] - prices[i - 1]);
				// sell k
				dp[e][2 * j + 2] = max(dp[!e][2 * j + 2], dp[!e][2 * j + 1] + prices[i - 1]);
			}
            e = !e;
		}
		int result = 0;
		for (int i = 0; i < dp[!e].size(); i += 2)
			result = max(result, dp[!e][i]);
		return result;
	}
};