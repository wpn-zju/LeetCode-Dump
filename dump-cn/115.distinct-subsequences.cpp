class Solution {
public:
	int numDistinct(string s, string t) {
		vector<vector<uint32_t>> dp(s.length() + 1, vector<uint32_t>(t.length() + 1, 0));
		for (int i = 0; i <= s.length(); ++i)
			dp[i][0] = 1;
		for (int i = 1; i <= t.length(); ++i)
			dp[0][i] = 0;
		for (int i = 1; i <= s.length(); ++i) {
			for (int j = 1; j <= t.length(); ++j) {
				dp[i][j] += dp[i - 1][j];
				if (s[i - 1] == t[j - 1])
					dp[i][j] += dp[i - 1][j - 1];
			}
		}
		return dp[s.length()][t.length()];
	}
};