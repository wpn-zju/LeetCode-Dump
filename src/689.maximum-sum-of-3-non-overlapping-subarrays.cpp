class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		vector<vector<int>> path(2, vector<int>(nums.size() - k + 1, 0));
		vector<vector<int>> dp(3, vector<int>(nums.size() - k + 1, 0));
		int sum = 0;
		for (int i = 0; i < k; ++i)
			sum += nums[i];
		dp[0][0] = sum;
		for (int i = 0; i < dp[0].size() - 1; ++i) {
			sum -= nums[i];
			sum += nums[i + k];
			dp[0][i + 1] = sum;
		}
		int mx = 0;
		int mx2 = 0;
		int mx3 = 0;
		int index = 0;
		int tmp = 0;
		for (int i = k; i < dp[0].size(); ++i) {
			if (dp[0][i - k] > mx)
				path[0][i] = tmp = i - k;
			else
				path[0][i] = tmp;
			dp[1][i] = dp[0][i] + (mx = max(mx, dp[0][i - k]));
		}
		tmp = 0;
		for (int i = 2 * k; i < dp[0].size(); ++i) {
			if (dp[1][i - k] > mx2)
				path[1][i] = tmp = i - k;
			else
				path[1][i] = tmp;
			dp[2][i] = dp[0][i] + (mx2 = max(mx2, dp[1][i - k]));
			if (dp[2][i] > mx3) {
				mx3 = dp[2][i];
				index = i;
			}
		}
		return { path[0][path[1][index]], path[1][index], index };
	}
};