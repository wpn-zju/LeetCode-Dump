class Solution {
public:
	int strangePrinter(string s) {
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
		return strangePrinter(s, dp, 0, s.size() - 1);
	}

	int strangePrinter(string& s, vector<vector<int>>& dp, int i, int j) {
		if (i > j)
			return 0;
		if (dp[i][j])
			return dp[i][j];
		while (i < j && s[j - 1] == s[j]) {
			--j;
		}
		dp[i][j] = strangePrinter(s, dp, i, j - 1) + 1;
		for (int m = i; m < j; ++m) {
			if (s[m] == s[j]) {
				dp[i][j] = min(dp[i][j], strangePrinter(s, dp, i, m) + strangePrinter(s, dp, m + 1, j - 1));
			}
		}
		return dp[i][j];
	}
};