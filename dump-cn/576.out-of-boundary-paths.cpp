class Solution {
public:
	int findPaths(int m, int n, int N, int i, int j) {
		vector<vector<vector<int64_t>>> dp(m + 2, vector<vector<int64_t>>(n + 2, vector<int64_t>(2, 0)));
		for (int i = 0; i < m + 2; ++i)
			for (int j = 0; j < n + 2; ++j)
				if (!i || i == m + 1 || !j || j == n + 1)
					dp[i][j][0] = dp[i][j][1] = 1;
		bool tag = true;
		while (N--) {
			for (int i = 1; i < dp.size() - 1; ++i)
				for (int j = 1; j < dp[0].size() - 1; ++j)
					dp[i][j][tag] = (dp[i + 1][j][!tag] + dp[i - 1][j][!tag] + dp[i][j + 1][!tag] + dp[i][j - 1][!tag]) % 1000000007;
			tag = !tag;
		}
		return dp[i + 1][j + 1][!tag];
	}
};