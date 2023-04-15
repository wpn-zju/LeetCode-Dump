class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		if (nums.size() % 2 == 0)
			return true;
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
			dp[i][i] = nums[i];
		for (int step = 2; step <= n; ++step) {
			for (int i = 0; i < n - step + 1; ++i) {
				if (step % 2)
					dp[i][i + step - 1] = max(nums[i] + dp[i + 1][i + step - 1], nums[i + step - 1] + dp[i][i + step - 2]);
				else
					dp[i][i + step - 1] = min(dp[i + 1][i + step - 1] - nums[i], dp[i][i + step - 2] - nums[i + step - 1]);
			}
		}
		return dp[0][n - 1] >= 0;
	}
};