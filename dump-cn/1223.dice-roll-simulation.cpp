class Solution {
public:
	int dieSimulator(int n, vector<int>& rollMax) {
		vector<int> sum(n, 0);
		vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(6, vector<int64_t>(15, 0)));
		dp[0][0][0] = dp[0][1][0] = dp[0][2][0] = dp[0][3][0] = dp[0][4][0] = dp[0][5][0] = 1;
		sum[0] = 6;
		for (int i = 1; i < n; ++i) {
			int64_t tmp = 0;
			for (int j = 0; j < 6; ++j) {
				dp[i][j][0] = sum[i - 1];
				for (int l = 0; l < rollMax[j]; ++l)
					dp[i][j][0] += (1000000007 - dp[i - 1][j][l]);
				for (int k = 1; k < rollMax[j]; ++k)
					dp[i][j][k] += dp[i - 1][j][k - 1];
				for (int64_t& i : dp[i][j])
					tmp += i %= 1000000007;
			}
			sum[i] = tmp % 1000000007;
		}
		return sum.back();
	}
};