static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
		for (int i = 0; i < dp.size(); ++i)
			dp[i][i] = 1;
		for (int step = 1; step < s.length(); ++step)
			for (int i = 0; i < s.length() - step; ++i)
				if (s[i] == s[i + step])
					dp[i][i + step] = dp[i + 1][i + step - 1] + 2;
				else
					dp[i][i + step] = max(dp[i][i + step - 1], dp[i + 1][i + step]);
		return dp[0][s.length() - 1];
	}
};