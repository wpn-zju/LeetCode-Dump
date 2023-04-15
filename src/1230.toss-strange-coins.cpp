class Solution {
public:
	double probabilityOfHeads(vector<double>& prob, int target) {
		vector<vector<double>> dp(prob.size() + 1, vector<double>(target + 1, 0));
		dp[0][0] = 1;
		for (int i = 1; i < dp.size(); ++i)
			dp[i][0] = dp[i - 1][0] * (1.0 - prob[i - 1]);
		for (int i = 1; i < dp.size(); ++i) {
			for (int j = 1; j < dp[0].size(); ++j) {
				dp[i][j] += dp[i - 1][j - 1] * prob[i - 1] + dp[i - 1][j] * (1.0 - prob[i - 1]);
			}
		}
		return dp.back().back();
	}
};