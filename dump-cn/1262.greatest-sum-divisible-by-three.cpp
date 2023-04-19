class Solution {
public:
	int maxSumDivThree(vector<int>& nums) {
		vector<vector<int>> dp(nums.size(), vector<int>(3, INT_MIN));
		for (int i = 0; i < nums.size(); ++i)
			dp[i][nums[i] % 3] = nums[i];
		for (int i = 1; i < nums.size(); ++i) {
			int mod = nums[i] % 3;
			dp[i][0] = max(dp[i][0], max(dp[i - 1][0], dp[i - 1][(3 - mod) % 3] + nums[i]));
			dp[i][1] = max(dp[i][1], max(dp[i - 1][1], dp[i - 1][(4 - mod) % 3] + nums[i]));
			dp[i][2] = max(dp[i][2], max(dp[i - 1][2], dp[i - 1][(5 - mod) % 3] + nums[i]));
		}
		return dp.back()[0] == INT_MIN ? 0 : dp.back()[0];
	}
};