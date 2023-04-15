class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		// 初始长度为 1
		vector<int> dp(nums.size(), 1);
		// 初始计数为长度为 1 的子序列 1 个
		vector<int> count(nums.size(), 1);
		for (int i = 1; i < nums.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (nums[i] > nums[j]) {
					if (dp[i] < dp[j] + 1) {
						dp[i] = dp[j] + 1;
						count[i] = count[j];
					}
					else if (dp[i] == dp[j] + 1) {
						count[i] += count[j];
					}
				}
			}
		}
		int mxL = 0;
		for (int& i : dp)
			mxL = max(mxL, i);
		int result = 0;
		for (int i = 0; i < count.size(); ++i)
			if (dp[i] == mxL)
				result += count[i];
		return result;
	}
};