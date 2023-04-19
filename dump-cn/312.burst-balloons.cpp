static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		vector<int> nums2(nums.size() + 2);
		nums2[0] = nums2[nums2.size() - 1] = 1;
		for (int i = 0; i < nums.size(); ++i)
			nums2[i + 1] = nums[i];
		vector<vector<int>> dp(nums2.size(), vector<int>(nums2.size(), 0));
		// i 为步长
		for (int i = 0; i < nums.size(); ++i)
			// j 为起始位置
			for (int j = 1; j < nums.size() - i + 1; ++j)
				// k 为i - j之间最后戳破的位置
				for (int k = j; k <= j + i; ++k)
					dp[j][j + i] = max(dp[j][j + i], dp[j][k - 1] + dp[k + 1][j + i] + nums2[j - 1] * nums2[k] * nums2[j + i + 1]);
		return dp[1][nums.size()];
	}
};