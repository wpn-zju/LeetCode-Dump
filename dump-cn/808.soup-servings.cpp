class Solution {
public:
	double soupServings(int N) {
		if (N >= 4300)
			return 1;
		N = ceil((double)N / 25);
		vector<vector<double>> dp(max(4, N + 1), vector<double>(max(3, N + 1), 0));
		dp[0][0] = 0.5;
		for (int i = 1; i < dp.size(); ++i)
			dp[i][0] = 0;
		for (int i = 1; i < dp[0].size(); ++i)
			dp[0][i] = 1;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				dp[i][j] += 0.25 * dp[max(0,i - 4)][j];
				dp[i][j] += 0.25 * dp[max(0,i - 3)][max(0,j - 1)];
				dp[i][j] += 0.25 * dp[max(0,i - 2)][max(0,j - 2)];
				dp[i][j] += 0.25 * dp[max(0,i - 1)][max(0,j - 3)];
			}
		}
		return dp[N][N];
	}
};