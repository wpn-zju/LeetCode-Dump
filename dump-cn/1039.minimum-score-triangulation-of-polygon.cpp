static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int minScoreTriangulation(vector<int>& nums) {
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
		for (int i = 0; i < dp.size(); ++i)
			for (int j = 0; j < dp.size(); ++j)
				dp[i][j] = 100000000 * (j - i >= 2);
		// i 为步长
		for (int i = 2; i < nums.size(); ++i)
			// j 为起始位置
			for (int j = 0; j < nums.size() - i; ++j)
				for (int k = j; k <= j + i; ++k)
					dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k][j + i] + nums[j] * nums[k] * nums[j + i]);
		return dp[0][nums.size() - 1];
	}
};