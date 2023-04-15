class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		int ptr = 0;
		vector<int> dp(days.back() + 1, 0);
		for (int i = 1; i < dp.size(); ++i) {
			if (i == days[ptr]) {
				if (i >= 30)
					dp[i] = min(dp[i - 1] + costs[0], min(dp[i - 7] + costs[1], dp[i - 30] + costs[2]));
				else if (i >= 7)
					dp[i] = min(dp[i - 1] + costs[0], min(dp[i - 7] + costs[1], costs[2]));
				else
					dp[i] = min(dp[i - 1] + costs[0], min(costs[1], costs[2]));
				++ptr;
			}
			else
				dp[i] = dp[i - 1];
		}
		return dp.back();
	}
};