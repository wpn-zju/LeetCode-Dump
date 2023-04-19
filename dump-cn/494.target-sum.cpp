static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0;
		for (int& i : nums)
			sum += i;
		if (S > sum || (sum - S) % 2)
			return 0;
		S = S + (sum - S) / 2;
		vector<int> dp(S + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); ++i)
			for (int j = dp.size() - 1; j >= nums[i]; --j)
				dp[j] += dp[j - nums[i]];
		return dp.back();
	}
};