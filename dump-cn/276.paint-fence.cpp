class Solution {
public:
	int numWays(int n, int k) {
		if (n == 0)
			return 0;
		vector<int> sum(n, 0);
		vector<int> dp(n, 0);
		sum[0] = k;
		dp[0] = 1;
		for (int i = 1; i < n; ++i) {
			dp[i] = sum[i - 1];
			for (int t = i - 2; t >= 0; --t) {
				if ((i - t) & 1)
					dp[i] += dp[t];
				else
					dp[i] -= dp[t];
			}
			sum[i] = dp[i] * k;
		}
		return sum.back();
	}
};