class Solution {
public:
	int numRollsToTarget(int d, int f, int target) {
		vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
		dp[0][0] = 1;
		for (int k = 1; k <= d; ++k) {
			for (int j = 1; j <= f; ++j) {
				for (int i = j; i <= target; ++i) {
					dp[k][i] += dp[k - 1][i - j];
					dp[k][i] %= 1000000007;
				}
			}
		}
		return dp.back()[target];
	}
};