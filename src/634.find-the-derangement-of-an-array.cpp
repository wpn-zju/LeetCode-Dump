class Solution {
public:
	int findDerangement(int n) {
		if (n == 1)
			return 0;
		vector<int64_t> dp(n);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i < dp.size(); ++i)
			dp[i] = i * (dp[i - 1] + dp[i - 2]) % 1000000007;
		return dp.back();
	}
};