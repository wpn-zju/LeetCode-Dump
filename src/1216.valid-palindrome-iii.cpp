class Solution {
public:
	bool isValidPalindrome(string s, int k) {
		vector<vector<int>> dp(s.size(), vector<int>(s.size()));
		for (int i = 0; i < s.size(); ++i)
			for (int j = 0; j < s.size(); ++j)
			    dp[i][j] = max(0, j - i - 1);
		for (int step = 1; step < s.size(); ++step) {
			for (int i = 0; i < s.size() - step; ++i) {
				if (s[i] == s[i + step])
					dp[i][i + step] = dp[i + 1][i + step - 1];
				else
					dp[i][i + step] = min(dp[i + 1][i + step], dp[i][i + step - 1]) + 1;
			}
		}
		return dp[0][s.size() - 1] <= k;
	}
};