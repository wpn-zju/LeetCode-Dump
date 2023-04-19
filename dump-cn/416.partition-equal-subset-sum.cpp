class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int& i : nums)
			sum += i;
		if (sum % 2)
			return 0;
		vector<bool> dp(sum / 2 + 1, false);
		dp[0] = true;
		for (int i = 0; i < nums.size(); ++i)
			for (int j = dp.size() - 1; j >= nums[i]; --j)
				dp[j] = dp[j] | dp[j - nums[i]];
		return dp.back();
	}
};