class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
        if (nums.size() == 1)
            return nums[0];
		vector<int> dp(nums.size() + 1);
		vector<int> dp2(nums.size());
		dp[0] = dp2[0] = 0;
		dp[1] = nums[0];
		dp2[1] = nums[1];
		for (int i = 2; i <= nums.size(); ++i)
			dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
		for (int i = 2; i < nums.size(); ++i)
			dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
		if (dp2.back() == dp.back() || dp.back() == dp[nums.size() - 1])
			return dp.back();
		else
			return max(dp[nums.size() - 1], dp2.back());
	}
};