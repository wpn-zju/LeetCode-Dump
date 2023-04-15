class Solution {
public:
	int tilingRectangle(int n, int m) {
		vector<vector<int>> dp(14, vector<int>(14, INT_MAX));
		for (int i = 0; i < dp.size(); ++i)
			dp[0][i] = dp[i][0] = 0;
		for (int x = 1; x < 14; ++x)
			for (int y = 1; y < 14; ++y)
				for (int i = min(x, y); i; --i) {
					dp[x][y] = min(dp[x][y], 1 + dp[x - i][y] + dp[i][y - i]);
					dp[x][y] = min(dp[x][y], 1 + dp[x - i][i] + dp[x][y - i]);
					for (int j = min(i - 1, y - i); j; --j)
						dp[x][y] = min(dp[x][y], 2 + dp[i - j][y - i] + dp[x - i + j][y - i - j] + dp[x - i][i + j]);
				}
		return dp[n][m];
	}
};