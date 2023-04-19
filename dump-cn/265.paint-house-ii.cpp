class Solution {
public:
	int minCostII(vector<vector<int>>& costs) {
		if (costs.empty())
			return 0;
		vector<int> mn1(costs.size());
		vector<int> mn2(costs.size());
		vector<vector<int>> dp(costs.size(), vector<int>(costs[0].size()));
		int mn_1 = INT_MAX, mn_1I = INT_MAX, mn_2 = INT_MAX, mn_2I = INT_MAX;
		for (int i = 0; i < costs[0].size(); ++i) {
			dp[0][i] = costs[0][i];
			if (dp[0][i] < mn_1) {
				mn_2 = mn_1;
				mn_2I = mn_1I;
				mn_1 = dp[0][i];
				mn_1I = i;
			}
			else if (dp[0][i] < mn_2) {
				mn_2 = dp[0][i];
				mn_2I = i;
			}
		}
		mn1[0] = mn_1I;
		mn2[0] = mn_2I;
		for (int i = 1; i < costs.size(); ++i) {
			mn_1 = mn_1I = mn_2 = mn_2I = INT_MAX;
			for (int n = 0; n < costs[0].size(); ++n) {
				if (mn1[i - 1] == n)
					dp[i][n] = dp[i - 1][mn2[i - 1]] + costs[i][n];
				else
					dp[i][n] = dp[i - 1][mn1[i - 1]] + costs[i][n];
				if (dp[i][n] < mn_1) {
					mn_2 = mn_1;
					mn_2I = mn_1I;
					mn_1 = dp[i][n];
					mn_1I = n;
				}
				else if (dp[i][n] < mn_2) {
					mn_2 = dp[i][n];
					mn_2I = n;
				}
			}
			mn1[i] = mn_1I;
			mn2[i] = mn_2I;
		}
		return dp.back()[mn1.back()];
	}
};